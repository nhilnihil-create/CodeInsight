#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <string>
#include <set>
#define INF 1000000000
#define LLINF 2000000000000000
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define LOOP(i,N) for(int i=0;i<N;i++)
#define LOOP1(i,N) for(int i=1;i<=N;i++)
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
#define int long long

signed main(){
	int a1,a2,b1,b2;
	int t1,t2;
	cin >> t1 >> t2;
	cin >> a1 >> a2;
	cin >> b1 >> b2;
	int s1 = a1-b1;
	int s2 = a2-b2;
	int d1 = s1 * t1;
	int d2 = s2 * t2;
	if(d1<0){
		d1*=-1;
		d2*=-1;
	}
	// int mode = d1<0 ? -1 : 1;
	if((d1+d2) < 0){
		// 有限回
		// cerr << mode << endl;
		int dd = (d1+d2)*-1;
		int dm = d1;
		// cerr << dd << "*" << dm << endl;
		int ans = (dm/dd) * 2;
		if(dm%dd){
			ans += 1;
		}
		cout << ans << endl;
	}else if((d1+d2) == 0){
		cout << "infinity" << endl;
	}else{
		cout << "0" << endl;
	}
	// cerr << "*" << d1+d2 << endl;
}
