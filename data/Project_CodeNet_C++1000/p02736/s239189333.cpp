    #include <bits/stdc++.h>
    using namespace std;
    //#include <boost/multiprecision/cpp_int.hpp>
    //using multiInt = boost::multiprecision::cpp_int;
     
    using ll = long long int;
    using ld = long double;
    using pii = pair<int, int>;
    using pll = pair<ll, ll>;
    template <typename Q_type>
    using smaller_queue = priority_queue<Q_type, vector<Q_type>, greater<Q_type>>;
     
    const int MOD_TYPE = 1;
    const ll MOD = (MOD_TYPE == 1 ? (ll)(1e9 + 7) : 998244353);
    const int INF = (int)1e9;
    const ll LINF = (ll)4e18;
    const ld DINF = 1e12;
    const ld PI = acos(-1.0);
    const ld EPS = 1e-11;
     
    #define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)
    #define rep(i, n) REP(i, 0, n)
    #define MP make_pair
    #define MT make_tuple
    #define YES(n) cout << ((n) ? "YES" : "NO") << "\n"
    #define Yes(n) cout << ((n) ? "Yes" : "No") << endl
    #define Possible(n) cout << ((n) ? "Possible" : "Impossible") << endl
    #define possible(n) cout << ((n) ? "possible" : "impossible") << endl
    #define Yay(n) cout << ((n) ? "Yay!" : ":(") << endl
    #define all(v) v.begin(), v.end()
    #define NP(v) next_permutation(all(v))
    #define dbg(x) cerr << #x << ":" << x << endl;
     
    vector<int> Dx = {0, 0, -1, 1, -1, 1, -1, 1, 0};
    vector<int> Dy = {1, -1, 0, 0, -1, -1, 1, 1, 0};
     
    //nCrの偶奇
    inline int C_parity(int n, int r)
    {
      return n == (r | (n - r));
    }
     
    int main()
    {
      cin.tie(0);
      ios::sync_with_stdio(false);
      cout << setprecision(30) << setiosflags(ios::fixed);
     
      int n;
      string s;
      cin >> n >> s;
      int sum = 0;
      rep(i, n)
      {
        sum ^= (s[i] - '0') * C_parity(n - 1, i) % 2;
      }
      if (sum)
      {
        cout << 1 << endl;
        return 0;
      }
      int b[1000010];
      rep(i, n - 1)
      {
        b[i] = abs(s[i] - s[i + 1]);
        if (b[i] == 1)
        {
          cout << 0 << endl;
          return 0;
        }
        b[i] /= 2;
      }
      sum = 0;
      rep(i, n - 1)
      {
        sum ^= (b[i] - '0') * C_parity(n - 2, i) % 2;
      }
      cout << (sum ? 2 : 0) << endl;
     
      return 0;
    }