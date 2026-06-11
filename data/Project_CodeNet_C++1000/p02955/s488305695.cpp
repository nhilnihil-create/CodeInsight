#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
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

ll N, K;
ll A[505];

bool check(ll a){
  vector<ll> arr1(N);
  vector<ll> arr2(N);
  ll sum1 = 0;
  ll sum2 = 0;
  for(int i=0;i<N;++i){
    arr2[i] = A[i]%a;
    arr1[i] = (a - (A[i]%a))%a;
    sum1 += arr1[i];
    sum2 += arr2[i];
  }
  sort(arr1.begin(), arr1.end());
  ll ans1;
  ll sum = 0;
  if(sum>=sum2) return true;
  for(int i=0;i<N;++i){
    sum += arr1[i];
    sum2 -= (a-arr1[i])%a;
    if(sum>=sum2) {
      ans1 = sum;
      break;
    }
  }
  if(ans1<=K) return true;
  else return false;
}

int main() {
  cin>>N>>K;
  ll sum = 0;
  for(int i=0;i<N;++i) {
    cin>>A[i];
    sum += A[i];
  }
  ll ans = 1;
  for(ll i=1;i*i<=sum;++i){
    if(sum%i==0){
      if(check(i)) ans = max(ans, i);
      if(check(sum/i)) ans = max(ans, sum/i);
    }
  }
  cout<<ans<<endl;
}

