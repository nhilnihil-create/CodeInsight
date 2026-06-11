#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1000000001;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  string s;
  cin >> s;
  a--;
  b--;
  c--;
  d--;

  if(b < c && c < d){
    // ABCD
    for(int i = a; i < d; ++i){
      if(s[i] == '#' && s[i+1] == '#'){
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;    
  }
  else if(c < b){
    // ACBD
    for(int i = a; i < c; ++i){
      if(s[i] == '#' && s[i+1] == '#'){
        cout << "No" << endl;
        return 0;
      }
    }
    for(int i = b; i < d; ++i){
      if(s[i] == '#' && s[i+1] == '#'){
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "Yes" << endl;
  }
  else{
    // ABDC
    for(int i = a; i < c; ++i){
      if(s[i] == '#' && s[i+1] == '#'){
        cout << "No" << endl;
        return 0;
      }
    }
    for(int i = b; i <= d; ++i){
      if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.'){
        cout << "Yes" << endl;
        return 0;
      }
    }
    cout << "No" << endl;
  }

  return 0;
}
