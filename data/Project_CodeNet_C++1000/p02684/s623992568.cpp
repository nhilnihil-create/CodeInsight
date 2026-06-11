#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tii;
#define rep(i,s,n) for(int i=(int)(s);i<(int)(n);i++)

ll N,K;
ll A[200010];

ll calc(){
  map<ll,ll> mp;
  ll cnt[N];
  ll num = 1;
  ll roop = 0;
  ll st = 0;
  for(ll i=0;i<=N;i++){
    if(mp[num]!=0){
      st = mp[num];
      roop = i-mp[num];
      break;
    }
    mp[num] = i;
    cnt[i] = num;
    num = A[num];
  }
  ll x = K-st;
  if(x<roop) return cnt[K];
  ll r = x%roop;
  return cnt[st+r];
}

int main(){
  cin >> N >> K;
  for(int i=1;i<=N;i++){
    cin >> A[i];
  }
  ll ans = calc();
  cout << ans << endl;
}

