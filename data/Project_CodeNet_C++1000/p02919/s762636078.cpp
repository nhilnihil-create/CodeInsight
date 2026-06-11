#include<bits/stdc++.h>
//#include"atcoder/all"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
//using namespace atcoder;
typedef long long ll;
int main(){
  ll N,i,p,ans = 0;scanf("%lld",&N);
  map<ll,ll> mp;
  for(i=0;i<N;i++){
    scanf("%lld",&p);
    mp[p] = i;
  }
  map<ll,ll> big;
  big[-1] = big[-2] = big[N] = big[N+1] = -1;
  ll place,fl,fr,sl,sr;
  for(i=N;i>=1;i--){
    place = mp[i];
    auto right1 = big.upper_bound(place);
    auto right2 = right1;right2++;
    auto left1 = right1;left1--;
    auto left2 = left1;left2--;
    if(left1->second == -1) fl = 0;
    else if(left2->second == -1) fl = left1->first+1;
    else fl = left1->first-left2->first;
    fr = (right1->second == -1 ? N-place:right1->first-place);
    if(right1->second == -1) sr = 0;
    else if(right2->second == -1) sr = N-right1->first;
    else sr = right2->first-right1->first;
    sl = (left1->second == -1 ? place+1:place-left1->first);
    ans += i*(fl*fr+sl*sr);
    big[place] = 1;
  }
  printf("%lld\n",ans);
}