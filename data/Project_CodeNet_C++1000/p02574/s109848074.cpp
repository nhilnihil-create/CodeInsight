#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int N = 1000100;
vector <int> prime;//i番目の素数
bool is_prime[1000100]; //is_prime[i] がTrueならiは素数

int sieve(int n){
  int p = 0;
  for (int i = 0; i <= n; i++) is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++){
    if (is_prime[i]){
      prime.emplace_back(i);
      for (int j = 2*i; j <=n; j+=i) is_prime[j] = false;
    }
  }
  return p;//pは素数の数
}

int main(){
  sieve(N);
  int n; cin >> n;
  vector<int>a(n);
  vector<int>c(N);
  rep(i, n){
    cin >> a[i];
    c[a[i]]++;
  }
  bool flag = true;
  for (int i:prime){
    int cnt = 0;
    for (int j = i; j <= N; j+=i){
      cnt += c[j];
    }
    if (cnt > 1){
      flag = false;
      break;
    }
  }
  int gcd = a[0];
  rep(i, n-1){
    gcd = __gcd(a[i+1], gcd);
  }
  if (flag) cout << "pairwise coprime" << endl;
  else if (gcd == 1) cout << "setwise coprime" << endl;
  else cout << "not coprime" << endl;
}