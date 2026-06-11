#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// DEBUG - Start of snippet
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
#define debug(...) 0
#endif
// DEBUG - End of snippet

// THINK: INT vs LONG LONG?

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int numA, numB, A, B, C;
	cin >> numA >> numB >> A >> B >> C;

	vector<int> a1(A), b1(B), c(C);
	for (int i = 0; i < A; ++i)
		cin >> a1[i];
	for (int i = 0; i < B; ++i)
		cin >> b1[i];
	for (int i = 0; i < C; ++i)
		cin >> c[i];

	sort(a1.rbegin(), a1.rend());
	sort(b1.rbegin(), b1.rend());
	sort(c.rbegin(), c.rend());

	vector<int> a(a1.begin(), a1.begin() + numA);
	vector<int> b(b1.begin(), b1.begin() + numB);
	long long a_sum = accumulate(a.begin(), a.end(), (long long) 0);
	long long b_sum = accumulate(b.begin(), b.end(), (long long) 0);

	debug(a, b);

	for (int i = 0; i < C; ++i) {
		int diff1 = (a.empty() ? - 1 : c[i] - a.back());
		int diff2 = (b.empty() ? -1 : c[i] - b.back());
		if (diff1 >= diff2 && diff1 > 0) {
			a_sum += diff1;
			a.pop_back();
		}
		else if (diff2 > diff1 && diff2 > 0) {
			b_sum += diff2;
			b.pop_back();
		}
	}

	long long ans = a_sum + b_sum;

	cout << ans << '\n';

	return 0;
}