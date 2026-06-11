    #include <bits/stdc++.h>
    using namespace std;

    //long long
    using ll = long long;

    // pair<int, int>
    using PII = pair<int, int>;

    //最大値、mod
    const int MOD = 1000000007;
    const int INF = 1000000000;
    const long long LINF = 1e18;

    //出力系
    #define print(x) cout << x << endl
    #define prints(x) cout << fixed << setprecision(10) << x << endl
    #define printc(x) cout << setw(2) << setfill('0') << x << endl;
    #define yes cout << "Yes" << endl
    #define YES cout << "YES" << endl
    #define no cout << "No" << endl
    #define NO cout << "NO" << endl
    
    // begin() end()
    #define all(x) (x).begin(),(x).end()

    //for
    #define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)

    //最大公約数 
    unsigned gcd(unsigned a, unsigned b) {
      if(a < b) return gcd(b, a);
      unsigned r;
      while ((r=a%b)) {
        a = b;
        b = r;
      }
      return b;
    }

    // 最小公倍数
    unsigned lcm(unsigned a, unsigned b){
        return a / gcd(a, b) * b; 
    }

    // a = max(a, b), a = min(a, b)
    template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
    template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

    //int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};









int main(){
  int N;
  cin >> N;
  int cnt = 0;
  vector<ll> x(N), y(N);
  REP(i, N) cin >> x.at(i) >> y.at(i);
  for(int i = 0; i < N; i++){
    for(int j = i + 1; j < N; j++){
      int tmp = 0;
      int a = x.at(i) - x.at(j);
      int b = y.at(i) - y.at(j);
      for(int i1 = 0; i1 < N; i1++)
        for(int j1 = 0; j1 < N; j1++){
          if(a == x.at(i1) - x.at(j1) && b == y.at(i1) - y.at(j1) && i1 != j1) tmp++;
        }
        chmax(cnt, tmp);
    }
  }
  int ans = N - cnt;
  print(ans);
  return 0;
}