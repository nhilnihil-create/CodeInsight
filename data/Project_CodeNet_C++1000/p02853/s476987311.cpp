#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int solve(int x){
  if(x==1)return 3*N;
  if(x==2)return 2*N;
  if(x==3)return N;
  return 0;
}
int main(){
  int a,b;
  cin>>a>>b;
  int ans=0;
  if(a==1&&b==1)ans=4*N;
  ans+=solve(a)+solve(b);
  cout<<ans<<endl;
  return 0;
}