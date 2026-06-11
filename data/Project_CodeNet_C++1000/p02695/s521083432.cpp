#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) { return '"' + s + '"'; }

string to_string(const char* s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}

template <size_t N>
string to_string(bitset<N> v) {
  string res = "";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + v[i]);
  }
  return res;
}

template <typename A>
string to_string(vector<A> v) {
  bool first = true;
  string res = "{";
  for (const auto& x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " +
         to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) void(0)
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> a(q), b(q), c(q), d(q);
  for (int i = 0; i < q; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  vector<int> a1(n + m - 1);
  for (int i = 1; i <= m - 1; i++) {
    a1[i] = 0;
  }
  for (int i = m - 1; i <= n + m - 2; i++) {
    a1[i] = 1;
  }
  int ans = 0;
  do {
    vector<int> v(1, 0);
    v.insert(v.end(), a1.begin(), a1.end());
    vector<int> w;
    int cnt = 0;
    for (auto vi : v) {
      if (vi == 0)
        cnt++;
      else
        w.emplace_back(cnt);
    }
    int sum = 0;
    for (int i = 0; i < q; i++) {
      if (w[b[i] - 1] - w[a[i] - 1] == c[i]) sum += d[i];
    }
    ans = max(ans, sum);
  } while (next_permutation(a1.begin(), a1.end()));
  cout << ans << '\n';
  return 0;
}