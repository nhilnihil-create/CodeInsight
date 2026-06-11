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
#define MAX_N 100100
#define MAX_M 100100

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<double, double> PD;
typedef pair<string, ll> PS;
typedef vector<ll> V;
typedef pair<P, char> PC;

bool f1[10], f2;
int n;
string s;

int main(){
	while (cin >> n&&n){
		int ans = 0;
		fill(f1, f1 + 10, 0);
		f2 = 0;
		REP(i, n){
			cin >> s;
			if (s == "ld"){
				f1[0] = 0;
				if (f2){
					if (!f1[0] && !f1[1]){
						ans++;
						f2 = 0;
					}
				}
			}
			else if (s == "rd"){
				f1[1] = 0;
				if (f2){
					if (!f1[0] && !f1[1]){
						ans++;
						f2 = 0;
					}
				}
			}
			else if (s == "lu"){
				f1[0] = 1;
				if (!f2){
					if (f1[0] && f1[1]){
						ans++;
						f2 = 1;
					}
				}
			}
			else if (s == "ru"){
				f1[1] = 1;
				if (!f2){
					if (f1[0] && f1[1]){
						ans++;
						f2 = 1;
					}
				}
			}
		}
		cout << ans << endl;
	}
}