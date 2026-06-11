#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using st = string;
using db = double;
using vll = vector<long long>;
using vvll = vector<vll>;
using vst = vector<st>;
using vchar = vector<char>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
#define rep(i, m, n) for (int i = (int)(m); i < (int)(n); i++)
#define vrep(i, vec) for(auto& i : vec)
#define vin(vec) for(auto& i : vec) cin >> i
#define all(v) v.begin(), v.end()
ll mod = 1000000007;

void dfs(st dokei, ll n){
  if(n == 1){
    cout << dokei << endl;
    return;
  }
  char max = 'a';
  vrep(i, dokei) if(max < i) max = i;
  rep(i, 0, max - 'a' + 2){
    st next = dokei;
    next.push_back((char)('a' + i));
    dfs(next, n - 1);
  }
}

int main(){
  ll n;
  cin >> n;
  dfs("a", n);
}