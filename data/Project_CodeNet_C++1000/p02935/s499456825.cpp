#include <bits/stdc++.h>
using namespace std;
 
int main(){
  double N;
  cin>>N;
  vector<double> v(N);
  for(int i=0;i<N;i++){
    cin>>v[i];
  }
  sort(v.begin(),v.end());
  for(int i=1;i<N;i++){
    v[0]=(v[0]+v[i])/2;
  }
  cout<<v[0]<<endl;
}