#include<bits/stdc++.h>
#define INF 9223372036854775807LL
#define inf 1000000007
#define lol long long
#define abs(x,y) (max(x,y)-min(x,y))
#define mp make_pair
#define fi first
#define se second
using namespace std;
lol a,b,c;
lol x,y;
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  lol d=0,e=0,f=0;
  lol ans=0;
  string s;
  cin >>x>>y;
  cin >>a>>b>>c>>d;
  e=(a-c)*x,f=(b-d)*y;
  if(e==-f){
    cout <<"infinity\n";
    return 0;
  }
  if(e<0) e=-e,f=-f;
  if(e+f>0){
    cout <<0<<'\n';
    return 0;
  }
  c=-e/(e+f);
  if(-e%(e+f)==0)
    cout <<c*2<<'\n';
  else cout <<c*2+1<<'\n';
  return 0;
}
