#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vs = vector<string>;
using msi = map<string, int>;
using mii = map<int, int>;
using psi = pair<string, int>;
using pii = pair<int, int>;
using vlai = valarray<int>;
#define rep(i,n) for(int i=0;i<n;i++)
#define range(i,s,n) for(int i=s;i<n;i++)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define INF 1E9
#define EPS 1E-9
#define MOD (ll)(1E9+7)
#define PI 3.1415926535897932384

template <class T>ostream &operator<<(std::ostream &o, const vector<T> &v)
{
	rep(i, v.size()) {
		o << (i > 0 ? " " : "") << v[i];
	}
	return o;
}



int main() {
	while (1) {
		string input;
		getline(cin,input);
		if (input == ".") break;
		stack<char> st;
		for (auto c : input) {
			if (c == '('||c=='[') {
				st.push(c);
			}
			else if (c == ')') {
				if (st.empty()||st.top()!='(') {
					st.push('!');
					break;
				}
				else {
					st.pop();
				}
			}
			else if (c == ']') {
				if (st.empty() || st.top() != '[') {
					st.push('!');
					break;
				}
				else {
					st.pop();
				}
			}
		}
		if (st.empty()) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
}

