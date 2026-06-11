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

int main() {
  int N;
  cin>>N;
  int P[N];
  int tmp;
  for(int i=0;i<N;++i) {
    cin>>tmp;
    P[tmp] = i;
  }
  set<int> st;
  auto bef1=st.begin(), bef2=st.begin(), aft1=st.begin(), aft2=st.begin(), now=st.begin();
  int bef11, bef22, aft11, aft22;
  ll ans = 0;
  for(ll i=N;i>0;--i){
    st.insert(P[i]);
    if(i==N) continue;
    now = st.find(P[i]);
    if(now!=st.begin()) {
      bef1 = prev(now);
      bef11 = *bef1;
    }
    else {
      bef1 = st.begin();
      bef11 = -1;
    }
    if(bef1!=st.begin()) {
      bef2 = prev(bef1);
      bef22 = *bef2;
    }
    else {
      bef2 = st.begin();
      bef22 = -1;
    }
    if(now!=prev(st.end())) {
      aft1 = next(now);
      aft11 = *aft1;
    }
    else {
      aft1 = prev(st.end());
      aft11 = N;
    }
    if(aft1!=prev(st.end())) {
      aft2 = next(aft1);
      aft22 = *aft2;
    }
    else {
      aft2 = prev(st.end());
      aft22 = N;
    }
    ans += i * (aft22-aft11) * (*now-bef11) + i * (bef11 - bef22) * (aft11 - *now);
  }
  cout<<ans<<endl;
}

