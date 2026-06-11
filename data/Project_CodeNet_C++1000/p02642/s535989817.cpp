/**
 *    author:  math2do
 *    created: 27.08.2020 16:18:50
**/

#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "true" : "false");
}

string to_string(const char &ch) {
  return "'" + string(1, ch) + "'";
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
  reverse(res.begin(), res.end());
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
  return "{" + to_string(p.first) + ", " + to_string(p.second) + "}";
}
 
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
  return "{" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + "}";
}
 
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
  return "{" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + "}";
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
#define debug(...) 42
#endif


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  } 
  sort(arr.begin(), arr.end());
  int upto = *max_element(arr.begin(), arr.end());
  vector <int> cnt(upto + 1, 0);
  for (int val : arr) {
    cnt[val]++;    
  } 
  //debug(arr);
  arr.resize(unique(arr.begin(), arr.end()) - arr.begin());
  //debug(arr);
  //debug(upto);
  vector <bool> seen(upto + 1, false);
  for (int val : arr) {
    for (int i = 2 * val; i <= upto; i += val) {
      seen[i] = true;
    } 
  }
  int ans = 0;
  for (int val : arr) {
    if (!seen[val] && cnt[val] == 1) {
      ans += 1;
    } 
  } 
  cout << ans << endl;
  return 0;
}
