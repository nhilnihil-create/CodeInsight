#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define rep(i,n) FOR(i,0,n)
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define vint vector<int>
#define vdouble vector<double>
#define vstring vector<string>
using namespace std;

#include<map>
#include<set>
#include<queue>

typedef long long ll;
typedef unsigned long long ull;

const int MAX_N = 1000000;
int S[MAX_N];
int T[MAX_N];
int SN, ST;

int main() {

	cin >> SN;
	rep(i, SN){ cin >> S[i]; }
	cin >> ST;
	rep(i, ST){ cin >> T[i]; }

	int ct = 0;
	rep(i, ST){
		int flag = 0;
		rep(j, SN){ if (S[j] == T[i]) { flag++; break; } }
		ct += flag;
	}
	cout << ct << endl;
}