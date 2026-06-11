#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = ll(1e9 + 7);
#define endl '\n'


template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char c) {
  return string(1,c);
}

string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}
 
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
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
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
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
 
void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef COMPETITIVE_PROGRAMMING_LOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) if(0){}
#endif

 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  // cin >> TT;
  ll n;
  cin >> n;
  vector<ll> A(n), B(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i] >> B[i];
  }
  nth_element(A.begin(), A.begin() + n/2, A.end());
  nth_element(B.begin(), B.begin() + n/2, B.end());
  if (n&1) {
    cout << B[n/2]-A[n/2]+1 << endl;
    return 0;
  }
  ll b1 = B[n/2];
  ll a1 = A[n/2];
  nth_element(A.begin(), A.begin() + (n-1)/2, A.end());
  nth_element(B.begin(), B.begin() + (n-1)/2, B.end());
  ll b2 = B[(n-1)/2];
  ll a2 = A[(n-1)/2];
  cout << (b1+b2)-(a1+a2)+1 << endl;
}
