#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;



int main() { 
  ll n, a, b, c, d; cin >> n >> a >> b >> c >> d;
  string s; cin >> s;

  rep(i, a, max(c, d)){
    if(s[i] == '#' && s[i+1] == '#'){
      puts("No");
      return 0;
    }
  }
  if(c < d){
    puts("Yes");
    return 0;
  }
  Rep(i, b-1, d-1){
    if(i-1 >= 0 && i+1 < n)
    if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.'){
      puts("Yes");
      return 0;
    }
  }
  puts("No");

  return 0;
}
