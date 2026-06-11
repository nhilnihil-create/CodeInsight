#include<bits/stdc++.h>
using namespace std;
int main(){
  double N;
  cin>>N;
  vector<double> v(N);
  for(int i=0; i<N; i++){
    cin>>v.at(i);
  }
  sort(v.begin(),v.end());
  for(int i=0; i<N-1; i++){
    v.at(i+1)=(v.at(i)+v.at(i+1))/2;
  }
  printf("%.10f\n",v.at(N-1));
  return 0;
}