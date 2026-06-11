#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
 
void debug_out() {cout<<endl;}
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cout << " " << to_string(H);
  debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 0
#endif


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin>>n;
    vector<int> a(n), p(n), q(n);
    iota(a.begin(), a.end(), 1);
    for (int i=0; i<n; ++i){
    	cin>>p[i];
    }
    for (int i=0; i<n; ++i){
    	cin>>q[i];
    }
    int done=0;
    int pos[2];
    int cnt=1;
    do{
    	debug(a, p, q);
    	if (a==p){
    		done++;
    		pos[0]=cnt;
    	}
    	if (a==q){
    		done++;
    		pos[1]=cnt;
    	}
    	cnt++;
    } while (next_permutation(a.begin(), a.end()) && done<2);
    cout<<abs(pos[0]-pos[1]);

    return 0;
}