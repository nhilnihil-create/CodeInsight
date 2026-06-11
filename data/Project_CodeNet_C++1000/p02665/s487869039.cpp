#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,s=0,ans=1;cin>>n;
  lvector A(n+1);rep(i,n+1) {cin>>A[i];s+=A[i];}
  if(A[0]==1) {print((n==0)?1:-1);return 0;}
  if(A[0]>1) {print(-1);return 0;}
  s-=A[0];
  ll root=1,num;
  for(ll d=1;d<=n;++d) {
    num=min(root*2,s);
    root=num-A[d];
    if(root<0) {ans=-1;break;}
    ans+=num;
    s-=A[d];
  }
  print(ans);
  return 0;
}