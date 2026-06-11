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

ll bit[200005];

void add(int index, ll x) {
  while(index<200005) {
    bit[index] += x;
    index += index&-index;
  }
}

ll getsum(int index1, int index2) {
  ll ans1=0, ans2=0;
  while(index1>0) {
    ans1 += bit[index1];
    index1 -= index1&-index1;
  }
  while(index2>0) {
    ans2 += bit[index2];
    index2 -= index2&-index2;
  }
  return ans2-ans1;
}

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
  vector<ll> arr1(N);
  for(int i=0;i<N;++i) arr1[i] = arr[i].fi;
  int index;
  ll tmp;
  ll ans=0;
  for(int i=0;i<N;++i) {
    X = arr[i].fi;
    H = arr[i].se;
    index = lower_bound(arr1.begin(), arr1.end(), arr1[i]-2*D)-arr1.begin()+1;
    tmp = getsum(index-1, i+1);
    H -= A*tmp;
    if(H<=0) ;
    else if(H%A==0) {
      ans += H/A;
      add(i+1, H/A);
    }
    else {
      ans += H/A+1;
      add(i+1, H/A+1);
    }
  }
  cout<<ans<<endl;
}

