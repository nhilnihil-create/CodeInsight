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

int n,k;

void solve() {
	read(n,k);
	ll a[n];
	vector<string> ans;
	for(int i = 0; i < n; ++i)
		read(a[i]);
	for(int i = 0; i + k < n; ++i) {
		ans.push_back(a[i] < a[i+k] ? "Yes" : "No");
	}
	print(ans);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	solve();
}
