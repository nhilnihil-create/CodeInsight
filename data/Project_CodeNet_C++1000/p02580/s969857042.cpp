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

string to_string(const char& c){
	string res;
	return "'" + res + c + "'";
}
 
string to_string(bool b) {
	return (b ? "True" : "False");
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
 
void debug_out() { cerr<<endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}
 
#ifdef LOCAL
#define debug(...) cerr << "\t[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else		
#define debug(...)
#endif	

// THINK: INT vs LONG LONG?

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);	
    int h, w, m;
    cin >> h >> w >> m;
    vector<int> r_cnt(h), c_cnt(w);
    // r_target.reserve(w), c_target.reserve(h);
    vector<pair<int, int>> targets(m);
    for (int i = 0; i < m; ++i){
    	int r, c;
    	cin >> r >> c;
    	--r, --c;
    	r_cnt[r]++;
    	c_cnt[c]++;
    	targets[i] = {r, c};
    }

   	// pick best row, then best col
   	int b_row = (int) (max_element(r_cnt.begin(), r_cnt.end()) - r_cnt.begin());
   	ll cnt = r_cnt[b_row];
   	vector<int> nc_cnt = c_cnt;
   	for (auto t: targets){
   		if (t.first == b_row) nc_cnt[t.second]--;
   	}
   	cnt += *max_element(nc_cnt.begin(), nc_cnt.end());
   	ll ans = cnt;

   	// pick best col, then row
   	int b_col = (int) (max_element(c_cnt.begin(), c_cnt.end()) - c_cnt.begin());
   	cnt = c_cnt[b_col];
   	vector<int> nr_cnt = r_cnt;
   	for (auto t: targets){
   		if (t.second == b_col) nr_cnt[t.first]--;
   	}
   	cnt += *max_element(nr_cnt.begin(), nr_cnt.end());
   	ans = max(ans, cnt);

   	cout << ans << '\n';
    return 0;
}