#define _CRT_SECURE_NO_WARNINGS // #pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <sstream>
#include <cmath>
#include <set>
#include <map>
using namespace std; 

#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define all(a) a.begin(),a.end()
#define len(x) ((int)(x).size())
#define tmax(a,b,c) max((a),max((b),(c)))
#define tmin(a,b,c) min((a),min((b),(c)))
#define debug(x) cerr << #x << " is " << x << endl;

typedef pair<int, int> Pii;
typedef vector<int> Vi;
typedef vector<vector<int> > VVi;
typedef long long ll;
const int inf = 2e9;
const ll ll_inf = 1e17;
const int mod = 1e9 + 7;
const long double eps = 1e-10;

int main()
{
	while(1) {
		string s;
		getline(cin, s);
		if (s.size() == 1 && s[0] == '.') break;

		string a;
		rep(i,0,s.size()) {
			if (s[i] == '(') a += '(';
			if (s[i] == ')') a += ')';
			if (s[i] == '[') a += '[';
			if (s[i] == ']') a += ']';
		}
		//debug(a);
		while (a.size() >= 2) {
			bool update = false;
			rep(i,0,a.size()-1) {
				if ((a[i] == '(' && a[i+1] == ')') || (a[i] == '[' && a[i+1] == ']')) {
					a = a.substr(0,i) + a.substr(i+2); 
					update = true;
					//debug(a);
				}
				else if (i == a.size()-2 && update == false) a = "x";
				if (a.size() < 2) break;
			}
		}

		if (a.size() == 0) cout << "yes" << endl;
		else cout << "no" << endl;
	}

	return 0;
}