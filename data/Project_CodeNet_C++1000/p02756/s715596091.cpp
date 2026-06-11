#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;
const double pi=acos(-1);





int main() 
{
  string S; cin>>S;
  bool judge=true;
  ll Q; cin>>Q;
  string A,B; A=B="";
  rep(i,Q)
  {
    int hoge; cin>>hoge;
    if(hoge==1) {judge=!(judge); continue;}
    int F; cin>>F;
    char C; cin>>C;
    if(F==1)
    {
      if(judge) {A+=C; continue;}
      B+=C;
      continue;
    }
    //F==2
    if(judge) {B+=C; continue;}
    A+=C;
  }
  S+=B;
  reverse(S.begin(),S.end());
  S+=A;
  if(judge){reverse(S.begin(),S.end());}
  cout<<S<<endl;
  return 0;
}
