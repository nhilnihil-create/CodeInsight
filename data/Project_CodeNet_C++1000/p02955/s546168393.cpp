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
  ll N, K;
  cin>>N>>K;
  ll A[N];
  ll sum = 0;
  for(int i=0;i<N;++i) {
    cin>>A[i];
    sum += A[i];
  }
  vector<ll> yaku;
  for(ll i=1;i*i<=sum;++i) {
    if(sum%i==0) {
      yaku.push_back(i);
      if(i!=sum/i) yaku.push_back(sum/i);
    }
  }
  ll ans = 1;
  for(int i=0;i<yaku.size();++i) {
    vector<int> arr1, arr2;
    for(int j=0;j<N;++j) arr1.push_back(A[j]%yaku[i]);
    sort(arr1.begin(), arr1.end());
    for(int j=0;j<N;++j) arr2.push_back(yaku[i]-arr1[j]);
    for(int j=N-2;j>=0;--j) arr2[j] += arr2[j+1];
    int tmp = 0;
    for(int j=0;j<N-1;++j) {
      tmp += arr1[j];
      if(tmp==arr2[j+1]) {
        if(tmp<=K) ans = max(ans, yaku[i]);
        break;
      }
    }
  }
  cout<<ans<<endl;
}

