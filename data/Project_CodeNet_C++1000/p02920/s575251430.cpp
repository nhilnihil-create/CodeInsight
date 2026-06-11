#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  multiset<int>a;
  rep(i,1<<n){int t;cin>>t;a.insert(t);}
  multiset<int>slime;
  bool flag=1;
  auto la=(a.lower_bound(1e9+7));
  la--;
  slime.insert(*la);
  rep(i,n)
  {
    multiset<int>dslime;
    for(auto tp:slime)
    {
      auto t=a.lower_bound(tp);
      if(t==a.begin()){flag=0;break;}
      t--;
      dslime.insert(*t);
      a.erase(t);
    }
    if(!flag)break;
    slime.insert(all(dslime));
  }
  if(flag)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;



  return 0;

}
