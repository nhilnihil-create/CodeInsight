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

string s;

int main(){
	while (getline(cin, s)){
		if (s == ".")break;
		bool f = 1, g = 0;
		vector<char> vc;
		vc.clear();
		REP(i, s.size()){
			if (s[i] == '('){
				vc.push_back(s[i]);
			}
			if (s[i] == '['){
				vc.push_back(s[i]);
			}
			if (s[i] == ')'){
				if (!vc.empty()){
					if (vc[vc.size() - 1] == '[')f = 0;
					else vc.pop_back();
				}
				else f = 0;
			}
			if (s[i] == ']'){
				if (!vc.empty()){
					if (vc[vc.size() - 1] == '(')f = 0;
					else vc.pop_back();
				}
				else f = 0;
			}
		}
		if ((vc.empty()&&g)||(vc.empty() && f))cout << "yes" << endl; 
		else cout << "no" << endl;
	}
}