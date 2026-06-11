#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define pi acos(-1.0)
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

int main(){
	int e;
	while (cin >> e && e){
		int ans = 1e9;
		for (int z = 0; z*z*z <= e; z++){
			for (int y = 0; z*z*z + y*y <= e; y++){
				int x = e - z*z*z - y*y;
				ans = min(ans, x+y+z);
			}
		}
		cout << ans << endl;
	}

    return 0;
}