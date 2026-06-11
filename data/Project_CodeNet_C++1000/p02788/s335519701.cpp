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
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll N, D, A;
  cin>>N>>D>>A;
  vector<pair<ll, ll> > arr(N);
  ll X, H;
  for(int i=0;i<N;++i) {
    cin>>X>>H;
    arr[i] = mp(X, H);
  }
  sort(arr.begin(), arr.end());
  int l=0;
  ll befsum = 0;
  ll ans[N];
  for(int i=0;i<N;++i) ans[i] = 0;
  for(int i=0;i<N;++i) {
    X = arr[i].fi;
    H = arr[i].se;
    while(l<i) {
      if(arr[i].fi-arr[l].fi>2*D) {
        befsum -= A*ans[l];
        l++;
      }
      else break;
    }
    H -= befsum;
    if(H<=0) ans[i] = 0;
    else if(H%A==0) ans[i] = H/A;
    else ans[i] = H/A+1;
    befsum += A*ans[i];
  }
  ll ans1 = 0;
  for(int i=0;i<N;++i) {
    ans1 += ans[i];
  }
  cout<<ans1<<endl;
}

