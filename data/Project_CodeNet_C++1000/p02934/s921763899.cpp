#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  double sum=0;
  vector<double> A(N);
  for(int i=0; i<N; i++){
    cin>>A.at(i);
    sum+=1/A.at(i);
  }
  printf("%.10f\n",1/sum);
  return 0;
}
  