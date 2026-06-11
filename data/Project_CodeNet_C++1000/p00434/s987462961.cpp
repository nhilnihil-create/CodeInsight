#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
 
//const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
//const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};
 
int main()
{
	map<int, bool> m;
	
	FOR(i, 1, 29){
		int tmp;
		cin >> tmp;
		m[tmp] = 1;
	}

	FOR(i, 1, 31){
		if (m[i] == 0){
			cout << i << endl;
		}
	}

}

