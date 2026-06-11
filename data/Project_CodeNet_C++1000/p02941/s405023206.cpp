#include <assert.h>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << i << "\n"

// const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll n,ans=0;
  std::cin>>n;

  std::vector<ll> a(n+2),b(n+2);

  rep(i,0,n)std::cin>>a[i];
  rep(i,0,n)std::cin>>b[i];
  a[n]=a[0];a[n+1]=a[1];
  b[n]=b[0];b[n+1]=b[1];

  std::priority_queue<P> que;

  rep(i,1,n+1){
    if((b[i]>b[i-1]+b[i+1])&&(b[i]!=a[i])){
      que.push(P(b[i],i));
    }
  }

  while(que.size()){
    P p=que.top();que.pop();
    ll itr=p.second;

    ll temp=MOD,x=b[itr-1]+b[itr+1];

    if((b[itr]-a[itr])%x==0)temp=(b[itr]-a[itr])/x;

    ll cnt=std::min((b[itr]-1)/x,temp);

    ans+=cnt;

    b[itr]-=cnt*x;

    b[0]=b[n];
    b[n+1]=b[1];

    itr=(itr+n-2)%n+1;
    if((b[itr]>b[itr-1]+b[itr+1])&&(b[itr]!=a[itr])&&(b[itr]>0)){
      que.push(P(b[itr],itr));
    }
    itr=(itr+n+1)%n+1;
    if ((b[itr] > b[itr - 1] + b[itr + 1]) && (b[itr] != a[itr]) &&
        (b[itr] > 0)) {
      que.push(P(b[itr], itr));
    }
  }

  rep(i,1,n+1){
    if(b[i]!=a[i]){
      std::cout<<-1;
      return 0;
    }
  }

  std::cout<<ans;

  return 0;
}
