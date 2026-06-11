#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int64_t> p(N);
  for(int i=0;i<N;i++){
    cin>>p[i];
  }
  int64_t Z=0,A=0;
  for(int i=N-1;i>0;i--){
    Z=max(Z,max(A,p[i-1]-p[i]));
    p[i-1]-=max(A,p[i-1]-p[i]);
  }
  if(Z<2){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}