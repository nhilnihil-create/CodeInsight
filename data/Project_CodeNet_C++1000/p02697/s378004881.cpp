#include<bits/stdc++.h>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define rrep(i,a) for(int i=(int)a-1;i>=0;--i)
#define REP(i,a,b) for(int i=(int)a;i<(int)b;++i)
#define RREP(i,a,b) for(int i=(int)a-1;i>=b;--i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
typedef std::vector<int> vi;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<long long> vl;
typedef std::vector<std::vector<long long>> vvl;
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}


ll gcd(ll n, ll m) {
    ll tmp;
    while (m!=0) {
        tmp = n % m;
        n = m;
        m = tmp;
    }
    return n;
}
 
ll lcm(ll n, ll m) {
    return abs(n) / gcd(n, m)*abs(m);//gl=xy
}

using namespace std;

void solve()
{
  int n, m;
  cin >> n >> m;
  if (n % 2)
  {
    rep(i,m){
      cout << i + 1 << " " << n - i << "\n";
    }
  }
  else{
    if(n%4){
      rep(i,m/2){
        cout << i + 1 << " " << n - i << "\n";
      }
      for (int i = m / 2; i < m;++i){
        cout << i + 1 << " " << n - i - 1 << "\n";
      }
    }
    else{
      rep(i,m/2+1){
        cout << i + 1 << " " << n - i << "\n";
      }
      for (int i = m / 2+1; i < m;++i){
        cout << i + 1 << " " << n - i - 1 << "\n";
      }
    }
  }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(15);
    solve();
    return 0;
}

