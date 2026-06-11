#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vecll vector<long long>
#define vec2ll vector<vector<long long>>
#define vecpairll vector<pair<long long,long long>>
#define forll(s,a,b) for(long long s = a;s < b;s++)
#define forllde(s,a) for(long long s = a;s > 0;s--)

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
#define debug(...) cerr << "<" << #__VA_ARGS__ << ">:", debug_out(__VA_ARGS__)
#define INF LLONG_MAX


// Run Length Encoding
vector<ll> countVector(vector<ll>v,ll guard=-1){
  ll size=v.size();
  v.push_back(guard);
  vector<ll>ret;
  ll count=1;
  for(int i=0;i<size;i++){
	if(v[i]==v[i+1]){
	  count++;
	}else{
	  ret.push_back(count);
	  count=1;
	}
  }
  return ret;
}


int main()
{
  string s;
  char b = 'R';
  cin >> s;
  vecll ans(s.size(), 0);
  vecll s_(s.size(), 0);
  vecll count;
  
  forll(i, 0, s.size()){
	if (s[i] == 'R') s_[i] = 0;
	else s_[i] = 1;
  }

  count = countVector(s_);

  ll b_i = 0;
  bool r = true;
  ll cum_i = 0;
  forll(i, 0, count.size()){
	if (r){
	  cum_i += count[i];
	  ans[cum_i - 1] += count[i] / 2 + count[i] % 2;
	  ans[cum_i] += count[i] / 2;
	  b_i = cum_i;
	  r = false;
	}else{
	  r = true;
	  ans[cum_i - 1] += count[i] / 2;
	  ans[cum_i] += count[i] / 2 + count[i] % 2;
	  cum_i += count[i];
	}
  }

  forll(i, 0, s.size())
	cout << ans[i] << ' ';
}
