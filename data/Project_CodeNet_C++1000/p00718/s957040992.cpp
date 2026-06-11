#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>

using namespace std;

#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,N) for(long long i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define fi first
#define se second

#define PI acos(-1.0)
#define INF 1000000007
#define EPS 1e-10

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<double, double> PD;
typedef pair<string, ll> PS;
typedef vector<ll> V;
typedef pair<P, char> PC;

int n, ans, k;
string s, t, a;

void solve(char c){
	if (c >= '2'&&c <= '9'){
		k = c - '0';
	}
	else{
		if (c == 'm'){
			k *= 1000;
		}
		else if (c == 'c'){
			k *= 100;
		}
		else if (c == 'x'){
			k *= 10;
		}
		ans += k;
		k = 1;
	}
}

string changes(int num){
	string res;
	stringstream ss;
	ss << num;
	ss >> res;
	return res;
}

int main(){
	cin >> n;
	REP(i, n){
		cin >> s >> t;
		ans = 0;
		k = 1;
		REP(i, s.size()){
			solve(s[i]);
		}
		REP(i, t.size()){
			solve(t[i]);
		}
		string f[4] = { "", "", "", "" };
		a = changes(ans);
		REP(i, a.size()){
			char c = a[a.size() - 1 - i];
			if (c != '0'){
				if (c != '1')f[i] += c;
				if (i == 0)f[i] += 'i';
				if (i == 1)f[i] += 'x';
				if (i == 2)f[i] += 'c';
				if (i == 3)f[i] += 'm';
			}
		}
		string q = f[3] + f[2] + f[1] + f[0];
		cout << q << endl;
	}
}