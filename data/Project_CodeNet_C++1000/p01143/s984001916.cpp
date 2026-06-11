#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>

using namespace std;

#define pb(n)	push_back(n)
#define mp(n,m) make_pair(n,m)
#define fi 	first
#define se 	second
#define all(r) (r).begin(),(r).end()

#define REP(i,s,e)	for(int i=(s); i<(e); i++)
#define rep(i,n)	REP(i,0,n)
#define REPE(i,s,e)	for(int i=s; i>e; i--)
#define repe(i,n)	REPE(i,n,-1)


typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

typedef vector<vi> vii;

const int IMAX = ((1 << 30) - 1) * 2 + 1;
const int INF = 100000000;
const double EPS = 1e-10;
//int mod=1000000007








int main(){
	int n, m, p;
	while (cin >> n >> m >> p){
		if (n == 0 && m == 0 && p == 0) break;
		int sum = 0, w, t;
		for (int i = 0; i < n; i++){
			cin >> t;
			sum += t;
			if (i == m - 1) w = t;
		}
		sum *= 100;
		double d = (double)sum*(100 - p) / 100;
		if (w == 0)cout << "0" << endl;
		else cout << (int)(d / w) << endl;
		//cout << sum << endl;
	}

}