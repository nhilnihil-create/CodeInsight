#include <bits/stdc++.h>
using namespace std;
#define _overload3(_1,_2,_3,_4,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,n) (int i=a;i<n;i++)
#define per(i,a,n,s) (int i=a;s>0?i<n:i>n;i+=s)
#define range(...) _overload3(__VA_ARGS__,per,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
template<class T>inline bool chmax(T &a, const T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T b) { if (b<a) { a=b; return 1; } return 0; }
const int inf = 1e9+10, mod = 1e9+7; const long long llinf = 1e18;
// head

int main(){
  int n,k;
  cin >> n >> k ;
  vector<int>data(k,0);
  for range(i,k){
    data[i] += 1;
  }
  n -= k;
  data[0] += n;
  cout << *max_element(all(data))-*min_element(all(data)) << endl;
}