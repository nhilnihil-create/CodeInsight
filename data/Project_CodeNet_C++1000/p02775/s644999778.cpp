#include <bits/stdc++.h>
using namespace std;

#define mainspring cout<<"mainspring\n";
#define barrel cout<<"barrel\n";
#define escapement cout<<"escapement\n";

#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end() 
#define sz(v) (int)((v).size())
#define fs first
#define sd second
#define tik(i,a,b) for(int i = a; i < b; i++)
#define tok(i,a,b) for(int i = a; i >= b; i--)
#define error(args...) {string _s = #args; replace(_s.begin(), _s.end(), ',',' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it,args);}

typedef long long ll;
typedef unsigned long long ull;

typedef pair < int, int > pi;
typedef pair < pi, int > ppi;

typedef vector < int > vi;
typedef vector < vector < int > > vvi;
typedef vector < pi > vpi;
typedef vector < vpi > vvpi;
typedef vector < ppi > vppi;

void fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void err(istream_iterator<string> it) {cout << endl;}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << " ";
    err(++it, args...);
}

ll pow(ll x, ll y) {
	if(y == 0)
	return 1;
	ll temp = pow(x, y/2);
	temp = (temp*temp);
	if(y%2 == 1)
		temp *= x;
	return temp;
}

int main() {
	string s;
	cin >> s;
	int n = sz(s) + 1;
	s = '0' + s;
	string tmp = s;
	string t = s;
	int res = 0;
	for(int i = n - 1; i >= 0; i--) {
		if(tmp[i] > '5' || (tmp[i] == '5' && tmp[i - 1] >= '5')) {
			// error(tmp[i], (int)(tmp[i] - '0'));
			t[i] = '0' + 10 - (int)(tmp[i] - '0');
			s[i] = '0';
			tmp[i - 1] += 1;
		}
		else {
			t[i] = '0';
			s[i] = tmp[i];
		}
	}
	res = 0;
	for(char ch : s) {
		res += ch - '0';
	}
	for(char ch : t) {
		res += ch - '0';
	}
	cout << res;
}
