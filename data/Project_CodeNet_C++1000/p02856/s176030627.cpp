#include <bits/stdc++.h>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
using namespace std;
using ll = long long;

int main()
{
  int M;
  cin >> M;

  ll order=0,sum=0;
  ll d,c;
  rep(i,M){
    cin >> d >> c;
    order += c;
    sum += d*c;
  }

  cout << (order-1)+((sum-1)/9) << "\n";
}
