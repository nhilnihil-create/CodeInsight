#include <bits/stdc++.h>

using namespace std;

#define FASTIO ios_base::sync_with_stdio(false), cin.tie(NULL)
#define pb push_back
#define all(x) x.begin, x.end
#define endl '\n'
#define mkp make_pair
#define trav(x, i) for(auto& i : x)

constexpr int INF =  1000000001;
constexpr int MOD =  1000000007;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;

int main(){
  FASTIO;
  map<string, int> m;
  int n = 0;
  cin >> n;
  int mx = INT_MIN;
  for(int i = 0; i < n; i++){
    string temp;
    cin >> temp;
    mx = max(++m[temp], mx);
  }
  for(const auto& i : m){
    if(i.second == mx){
      cout << i.first << endl;
    }
  }
  return 0;
}
