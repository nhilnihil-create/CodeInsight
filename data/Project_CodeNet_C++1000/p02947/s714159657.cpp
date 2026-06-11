#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long i=0; i<(int)n; i++)
#define rep2(i,a,n) for(long long i=(a); i<(int)(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using vll = vector<ll>;
using pii = pair<int, int>;
using psi = pair<string, int>;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};
const ll mod = 1e9+7;
int gcd(int a, int b){if(a%b == 0){return(b);}else{return(gcd(b, a%b));}}
int lcm(int a, int b){return a * b / gcd(a, b);}

ll N, M, K, H, W, L, R, X;
string S, T;



int main(){
  cin >> N;
  unordered_map<string, int> mp;
  ll ans = 0;
  rep(i,N){
    string s; cin >> s;
    sort(all(s));
    ans += mp[s];
    mp[s]++;
  }
  cout << ans << endl;
}