/**************************
*                         *
*  Nothing Is Impossible  *
*                         *
**************************/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>
#include <vector>
#include <thread>
#include <math.h>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <set>
#include <map>
#define GetRand(Min, Max) ((rand()%(int)(((Max) + 1)-(Min))) + (Min))
#define Rep(i, min, max) for(int i = min; i < max; ++i)
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef long double ld;
using namespace std;

void Solve(){
	int a,b,c;	cin >> a >> b >> c;
	int ans = 0, num = a;
	while(num <= b){
		if(num % c == 0){
			ans++;
		}
		num++;
	}
	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
	int t = 1;
	//int t;	cin >> t;
	while(t--) Solve();
	return 0;
}
