#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <tuple>
#include <numeric>
#include <time.h>
#include <chrono>
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define REP(i,a,b) for(ll i=a;i>b;i--)
#define CST(x) cout<<fixed<<setprecision(x)//小数点以下の桁数指定
#define ct(a) cout<<a<<endl
#define rep(i,n) for(int i=0;i<(n);i++)
#define repl(i,l,r) for(int i=(1);i<(r);i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
static const double pi = 3.141592653589793;
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
const ll INF = 1e9 + 7;
const ll mod = 1e9 + 7;

int N;
ll A[200001], B[200001];

int main() {


	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N;
	FOR(i, 0, N) {
		cin >> A[i] >> B[i];
	}
	sort(A, A + N); sort(B, B + N);

	if (N % 2 == 1) {
		cout << B[(N - 1) / 2] - A[(N - 1) / 2]+1 << endl;
	}
	else {
		cout << 1+B[N / 2] + B[N / 2 - 1] - A[N / 2] - A[N / 2 - 1]<<endl;
	}



	return 0;
}
