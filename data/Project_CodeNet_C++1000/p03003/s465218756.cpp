#include<bits/stdc++.h>
using namespace std;

const int mod = 7 + (1e+9);

template<long long mod>
class modint{
private:
  long long num;
  long long extgcd(long long a, long long b, long long&x, long long&y)const {
    long long d = a;
    if(b != 0){d = extgcd(b, a%b, y, x);  y -= (a/b) * x;}
    else{x = 1; y = 0;}
    return d;
  }
  long long modinverse()const{
    long long x, y;
    extgcd(num, mod, x, y);
    return (mod + x%mod)%mod;
  }
public:
  modint():num(0){}
  modint(const long long x):num((x < 0?(x+mod):x)%mod ){}
  friend modint operator+(const modint&a, const modint&b)
  {    return modint(a.num + b.num);  }
  friend modint operator-(const modint&a, const modint&b)
  {    return modint(a.num - b.num);  }
  friend modint operator*(const modint&a, const modint&b)
  {    return modint(a.num * b.num);  }
  friend modint operator/(const modint&a, const modint&b)
  {    return modint(a*b.modinverse());  }
  friend ostream& operator<<(ostream&os, const modint&a){
    os << a.num;
    return os;
  }
};

int main(){
  int n,m; cin >> n >> m;
  deque<int> s(n),t(m);
  for(auto&e:s)cin >> e;
  for(auto&e:t)cin >> e;
  s.push_front(0);
  t.push_front(0);
  modint<mod> dp[2010][2010] = {};
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      modint<mod> x = (s[i]==t[j]?dp[i-1][j-1]+1:0);
      dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + x;      
    }
  }
  cout << dp[n][m]+1 << endl;
  return 0;
}
