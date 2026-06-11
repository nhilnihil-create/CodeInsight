#include<bits/stdc++.h>
using namespace std;

#define ll long long
const char newl = '\n';

//***---***---***---Useless Code---***---***---***//

template<class T> void read(T &t) {
	cin >> t;
}
template<class A, class...B> void read(A& a, B&... b) {
	read(a);
	read(b...);
}
template<class T> void read(vector<T>& vt) {
	for(auto &a : vt)
		read(a);
}

string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(char c) { return string(1, c); }
string to_string(string s) { return s; }
string to_string(const char* str) { return string(str); }
string to_string(vector<bool> vt) {
	string ret;
	bool ft = 1;
	for(bool x : vt) {
		if(!ft)
			ret += ' ';
		ft = 0;
		ret += char('0' + x);
	}
	return ret;
}
template<class T> string to_string(vector<T> vt) {
	string ret;
	bool ft = 1;
	for(auto a : vt) {
		if(!ft)
			ret += ' ';
		ft = 0;
		ret += to_string(a);
	}
	return ret;
}

template<class T> void write(T t) {
	cout << to_string(t);
}
template<class A, class... B > void write(A a, B... b) {
	write(a);
	if(sizeof...(b))
		write(' ');
	write(b...);
}
void print() {
	write(newl);
}
template<class A, class... B> void print(A a, B... b) {
	write(a);
	if(sizeof...(b))
		write(' ');
	print(b...);
}

//***---***---***---Useless Code---***---***---***//

int n;

void solve() {
	ll ans = 1000, cnt = 0;
	read(n);
	vector<int> a(n);
	read(a);
	for(int i = 1; i < n; ++i) {
		if(a[i-1] < a[i]) {
			cnt = ans / a[i-1];
			ans += cnt * (a[i] - a[i - 1]);
		}
	}
	print(ans);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
