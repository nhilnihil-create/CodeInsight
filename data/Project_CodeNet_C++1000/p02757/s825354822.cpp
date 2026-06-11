#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll N, P;
  cin>>N>>P;
  string S;
  cin>>S;
  vector<ll> arr(S.size()+1);
  arr[0] = 0;
  ll num = 1;
  if(P==2) {
    ll ans = 0;
    for(ll i=0;i<S.size();++i) {
      if((S[i]-'0')%2==0) ans += i+1;
    }
    cout<<ans<<endl;
    return 0;
  }
  if(P==5) {
    ll ans = 0;
    for(ll i=0;i<S.size();++i) {
      if(S[i]=='0' || S[i]=='5') ans += i+1;
    }
    cout<<ans<<endl;
    return 0;
  }
  for(ll i=0;i<N;++i) {
    arr[i+1] = (arr[i]+num*(S[N-1-i]-'0'))%P;
    //arr[i+1] = (arr[i+1]+P)%P;
    num *= 10;
    num %= P;
  }
  /**
  for(ll i=0;i<=N;++i) cout<<arr[i]<<" ";
  cout<<endl;
  **/
  map<ll, ll> amap;
  vector<ll> arr1;
  for(ll i=0;i<=N;++i) {
    if(amap[arr[i]]==0) arr1.push_back(arr[i]);
    amap[arr[i]]++;
  }
  ll ans = 0;
  for(ll i=0;i<arr1.size();++i) {
    ans += amap[arr1[i]]*(amap[arr1[i]]-1)/2;
  }
  cout<<ans<<endl;
}
