#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
using namespace std;
using ll = long long;
using ld = long double;
template<class T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

int main(){
  ios_base::sync_with_stdio(false);cin.tie(0);
  ll N;
  cin >> N;
  if(N==2){
    cout << 1 << endl;
    return 0;
  }

  int ans=1;
  for(ll i=1;i*i<=N-1;i++){
    ll tmp=N-1;
    if(tmp%i==0){
      ans+=2;
      if(i==1 || i*i==tmp)  ans--;
    }
  }
  for(ll i=2;i*i<=N;i++){
    ll tmp=N;
    if(tmp%i!=0)  continue;
    while(tmp%i==0) tmp/=i;
    if(tmp%i==1)  ans++;
  }
  cout << ans << endl;

  return 0;
}