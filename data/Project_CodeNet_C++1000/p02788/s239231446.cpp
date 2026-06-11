#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) (a).begin(),(a).end()
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,d,a,x,h,ans=0;cin>>n>>d>>a;
  vector<P> mons(n);rep(i,n) {cin>>x>>h;mons[i]=P(x,h);}
  sort(ALL(mons));
  queue<P> prev_attacks;
  ll damage=0;
  for(ll tag=0;tag<n;tag++) {
    while(prev_attacks.size()&&prev_attacks.front().first<mons[tag].first) {
      damage-=a*prev_attacks.front().second;prev_attacks.pop();
    }
    mons[tag].second-=damage;
    ll num=(mons[tag].second+a-1)/a;
    if(num>0) {
      ans+=num;
      damage+=a*num;
      prev_attacks.emplace(mons[tag].first+2*d,num);
    }
  }
  print(ans);
  return 0;
}