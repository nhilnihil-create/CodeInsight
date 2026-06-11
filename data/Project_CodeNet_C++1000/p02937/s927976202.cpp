#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(v) v.begin(), v.end()
#define allR(v) v.rbegin(), v.rend()
#define PRINT(v) for (auto x : (v)) cout <<x <<" " ; cout <<endl;
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
typedef pair<int,int> Pi;
const ll MOD = 1000000007;
const ll INF = 10000000000000000;
const int inf = 1001001001;
vector<int> x4 = {0, 1, 0, -1}, x8 = {0, 1, 1, 1, 0, -1, -1, -1};
vector<int> y4 = {1, 0, -1, 0}, y8 = {1, 1, 0, -1, -1, -1, 0, 1};
template<class T> inline bool chmin(T& a, T b){if (a>b){a = b; return true;}return false;}
template<class T> inline bool chmax(T& a, T b){if (a<b){a = b; return true;}return false;}
template<class T> inline T powerM(T a,T b){if (b==0) return 1;
T tmp = powerM(a,b/2); if (b%2==0) return tmp*tmp%MOD; else return tmp*tmp%MOD*a%MOD; }
template<class T> inline T power(T a,T b,T m){ if (b==0) return 1;
  T tmp = power(a,b/2,m); if (b%2==0) return tmp*tmp%m; else return tmp*tmp%m*a%m; }
template<class T> inline T gcd(T a, T b){if (b==0) return a; return gcd(b, a%b);}
template<class T> inline T lcm(T a, T b){return a / gcd(a,b) * b;}
// ax+by=gcd(a,b)を解く
template<class T> inline T extgcd(T a,T b,T &x,T &y){if (b==0){x=1; y=0; return a;} T d=extgcd(b,a%b,y,x); y -= a/b*x; return d;}
void hey(){ cout <<"hey" <<endl; }

template<class T> struct edge { int to; T cost;};


void solve(string &s, string &t, vector<vector<int>> &alphabets){
  vector<ll> tindex(t.size(), 1000000000000000);
  rep(i, t.size()){
    if (alphabets[t[i] - 'a'].size() == 0){
      cout <<-1 <<endl; return;
    }
  }
  tindex[0] = alphabets[t[0] - 'a'][0];
  ll m = s.size();

  for (int i=1; i<t.size(); i++){
    auto &e = alphabets[t[i]-'a'];
    // eの中の各々のindexにmの倍数を足したもののうち、
    // tindex[i-1] より大きいものの最小値をtindex[i] とする
    // tindex[i-1]%m より大きいもののうち最小のものをまず探す
    // なければ最初のやつで
    ll a = 0;
    if (upper_bound(all(e), tindex[i-1]%m) == e.end()){
      a = e[0];
      a += tindex[i-1]/m*m;
      a += m;
    }else{
      a = *upper_bound(all(e), tindex[i-1]%m);
      a += tindex[i-1]/m*m;
    }
    // aにmの倍数を足してtindex[i-1]を超えるようにする
    tindex[i] = a;
  }
  ll res = tindex[t.size()-1] + 1;
  cout <<res <<endl;
}

int main() {
  string s,t; cin >>s >>t;
  vector<vector<int>> alphabets(26);
  rep(i, s.size()) alphabets[s[i]-'a'].push_back(i);
  // sの中のアルファベットがどのindexで現れたかを二次元配列で格納
  solve(s, t, alphabets);
  return 0;

  vector<int> abindex(26, 0);
  vector<ll> tindex(t.size(), -1);
  rep(i, t.size()){
    int alphb = t[i] - 'a';
    if (alphabets[alphb].size() == 0){
      cout <<-1 <<endl; return 0;
    }
    tindex[i] = alphabets[alphb][abindex[alphb]];
    abindex[alphb]++;
    abindex[alphb] %= alphabets[alphb].size();
  }

  ll m = s.size();

  for (int i=0; i<t.size()-1; i++){
    // tindex[i] と tindex[i+1] を比較。
    // 後者が小さければ m の倍数を足してでかくする
    tindex[i+1] += tindex[i]/m*m;
    while (tindex[i] >= tindex[i+1]){
      tindex[i+1] += m;
    }
  }
  ll res = tindex[t.size()-1] + 1;
  cout <<res <<endl;
}
