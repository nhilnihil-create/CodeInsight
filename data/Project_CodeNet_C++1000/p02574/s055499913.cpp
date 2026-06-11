#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int MOD = 1e9 + 7;
const int INF = 1001001001;

const int A = 1000005;

 ll gcd(ll a,ll b){
     if(a<b) swap(a,b);
     bool have_mod =true;
     while(have_mod){
         ll mod = a % b;
         if(mod == 0 ) have_mod = false;
         a = b;
         b = mod;
     }
     return a;
 }

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> c(A);
  rep(i,n) {
    cin >> a[i];
    c[a[i]]++;
  }
 
  bool pairwise = true;
  for (int i = 2; i < A; i++) {
    int cnt = 0;
    for (int j = i; j < A; j += i) {
      cnt += c[j];
    }
    if (cnt > 1) pairwise = false;
  }
 
  if (pairwise) {
    cout << "pairwise coprime" << endl;
    return 0;
  }
 
  int g = 0;
  rep(i,n) g = gcd(g,a[i]);
  if (g == 1) {
    cout << "setwise coprime" << endl;
    return 0;
  }
 
  cout << "not coprime" << endl;
  return 0;
}
