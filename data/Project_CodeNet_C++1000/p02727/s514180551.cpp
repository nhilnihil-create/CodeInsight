#include <bits/stdc++.h>
#define watch(x) cout <<(#x)<<" is "<<(x)<<endl
#define debug cout <<"hi"<<endl
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
int main(){
  int x,y,a,b,c; cin >>x >>y >>a >>b >>c; ll ans=0;
  priority_queue<int>p; priority_queue<int>q; priority_queue<int>r;
  for(int i=0; i<a; i++){int pp; cin >>pp; p.push(pp);}
  for(int i=0; i<x; i++){int pp=p.top(); r.push(pp); p.pop();}
  for(int i=0; i<b; i++){int qq; cin >>qq; q.push(qq);}
  for(int i=0; i<y; i++){int qq=q.top(); r.push(qq); q.pop();}
  for(int i=0; i<c; i++){int rr; cin >>rr; r.push(rr);}
  for(int i=0; i<x+y; i++){int s=r.top(); ans+=s; r.pop();}
  cout <<ans;
return 0;}