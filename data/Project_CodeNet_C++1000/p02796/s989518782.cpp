#include <bits/stdc++.h>
#define rep2(i,m,n) for (int i = (int)(m); i < (int)(n); i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
using ll = long long;
typedef pair<int, int> P;
template <typename T>
T sq(T x){
  return x * x;
}
const int MAX_N = 1e5;
signed main (){
  int N;
  cin >> N;
  vector<ll> X(N),L(N);
  rep(i,N){
cin >> X.at(i) >> L.at(i);
  }
  
P range[MAX_N];
  rep(i,N){
  int min = X.at(i) - L.at(i);
int max = X.at(i) + L.at(i);
range[i] = P(max,min); 
  
  }

sort(range,range + N);
ll cur = -1000000000;
ll ans = 0;
rep(i,N){
if (cur <= range[i].second) {
  ans ++;
  cur = range[i].first;
}

}
cout << ans << endl;
return 0;
}
