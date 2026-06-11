#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <cassert>
#include <functional>

using namespace std;

#define LOG(...) printf(__VA_ARGS__)
//#define LOG(...)
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).rbegin(),(c).rend())
#define CLR(a) memset((a), 0 ,sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int dx[] = { -1, 0, 1, 0 }; const int dy[] = { 0, 1, 0, -1 };
struct move2{
	char c;
	int m;
};

int main() {
	float n;
	while (cin >> n, n){
		int px = 10, py = 10;
		bool field[21][21];
		REP(i, 21)
			REP(j, 21)
			field[i][j] = false;
		REP(i, n){
			int x, y;
			cin >> x >> y;
			field[x][y] = true;
		}

		int mn;
		cin >> mn;
		REP(i, mn){
			char c;
			int m;
			cin >> c >> m;
			REP(j, m){
				if (c == 'N')py++;
				if (c == 'E')px++;
				if (c == 'S')py--;
				if (c == 'W')px--;
				field[px][py] = false;
			}
		}
		int count = 0;
		REP(i,21){
			REP(j,21){
				if (field[i][j]){
					count++;
				}
			}
		}
		cout << (count==0 ? "Yes" : "No") << endl;
	}
}