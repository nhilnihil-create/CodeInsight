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

ll n;
void dfs(st dokei, char max){
  if(dokei.size() == n) {
    cout << dokei << endl;
    return;
  }
  for(char i = 'a'; i < max + 2; i++){
    st next = dokei;
    next.push_back(i);
    ll nmax = (max > i ? max : i);
    dfs(next, nmax);
  }
}

int main(){
  cin >> n;
  dfs("a", 'a');
}