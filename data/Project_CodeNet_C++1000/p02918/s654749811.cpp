#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

const char wall = '#';
vector<vector<char>> fields;
vector<vector<bool>> used;
vector<vector<ll>> dist;
const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};

vector<ll> A;
// vectorのリサイズ
// A.resize(N);

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return b/gcd(a,b)*b;}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  deque<char> deq;
  deq.push_back(s[0]);
  rep(i, n) {
    char end = deq.back(); 
    if (end != s[i]) deq.push_back(s[i]);
  }
  ll ans = n - deq.size();
  cout << min(n-1, ans+2*k) << endl;
  return 0;
}
