#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RREP(i,x) for(int i=(x)-1;i>=0;i--)
#define RFOR(i,c) for(auto i=(c).rbegin();i!=(c).rend();++i)
#define ALL(container) container.begin(), container.end()
#define SZ(container) ((int)container.size())

const int INF = 1<<28;
const double EPS = 1e-8;
const int MOD = 1000000007;

main(){
	vector<pii> db;
	for(int w=1;w<=150;w++)
		for(int h=1;h<w;h++)
			db.push_back(pii(w*w+h*h, h));
	sort(db.begin(), db.end());
	int w, h;
	while(cin >> h >> w, h){
		pii tar(w*w+h*h, h);
		tar = *upper_bound(db.begin(), db.end(), tar);
		cout << tar.second << " " << (int)(1e-8+sqrt(tar.first - tar.second*tar.second)) << endl;
	}
	return 0;
}