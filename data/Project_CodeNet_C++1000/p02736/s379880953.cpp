#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define printP(x) "(" << (x).first << ", " << (x).second << ")"
#define mod 998244353
using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> E;

llint n;
llint a[1000005];

llint calc()
{
	llint ret = 0;
	for(int i = 0; i < n; i++){
		if(a[i] && ((n-1)&i) == i) ret++;
	}
	return ret%2;
}

int main(void)
{
	cin >> n;
	char c;
	for(int i = 0; i < n; i++){
		cin >> c;
		a[i] = c-'0', a[i]--;
	}
	
	bool flag = false;
	for(int i = 0; i < n; i++){
		if(a[i] % 2) flag = true;
	}
	if(flag){
		for(int i = 0; i < n; i++) a[i] %= 2;
		cout << calc() << endl;
	}
	else{
		for(int i = 0; i < n; i++) a[i] /= 2;
		cout << calc()*2 << endl;
	}
	
	return 0;
}
