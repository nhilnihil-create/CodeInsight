#include <bits/stdc++.h>

using namespace std;

#define FOR(i, m, n) for (int i = m; i < n; ++i)
#define FORD(i, m, n) for (int i = m; i >= n; --i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REP1(i, n) for (int i = 0; i <= n; ++i)
#define REPR(i, n) for (int i = n; i >= 0; --i)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

using ll = long long;
using ull = unsigned long long;
using ld = long double;

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int a[9];
	REP(i,9)cin>>a[i];
	int n;
	cin>>n;
	vector<int> b(n);
	REP(i,n){
		cin>>b[i];
		REP(j,9){
			if(b[i]==a[j])a[j]=0;
		}
	}
	if(a[0]==0&&a[1]==0&&a[2]==0)cout << "Yes" << endl;
	else if(a[0]==0&&a[4]==0&&a[8]==0)cout << "Yes" << endl;
	else if(a[0]==0&&a[3]==0&&a[6]==0)cout << "Yes" << endl;
	else if(a[6]==0&&a[7]==0&&a[8]==0)cout << "Yes" << endl;
	else if(a[6]==0&&a[4]==0&&a[2]==0)cout << "Yes" << endl;
	else if(a[2]==0&&a[5]==0&&a[8]==0)cout << "Yes" << endl;
	else if(a[3]==0&&a[4]==0&&a[5]==0)cout << "Yes" << endl;
	else if(a[1]==0&&a[4]==0&&a[7]==0)cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}