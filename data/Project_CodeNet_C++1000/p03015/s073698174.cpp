#include<bits/stdc++.h>
using namespace std;
const int M=1000000007;
long p[100003];
long solve(const string& S,long o){
  if(S.length()-o==1)return 2*(S[o]=='1')+1;
  if(S[o]=='0')return solve(S,o+1);
  return (p[S.length()-o-1]+2*solve(S,o+1))%M;
}void init(){long x=1;for(long i=0;i<100003;i++){p[i]=x;x=x*3%M;}}
int main(){init();string S;cin>>S;cout<<solve(S,0);}