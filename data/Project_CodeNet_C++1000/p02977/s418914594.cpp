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

int main(void)
{
	cin >> n;
	if((n&(n-1)) == 0){
		cout << "No" << endl;
		return 0;
	}
	
	cout << "Yes" << endl;
	cout << 1 << " " << 2 << endl;
	cout << 2 << " " << 3 << endl;
	cout << 3 << " " << n+1 << endl;
	cout << n+1 << " " << n+2 << endl;
	cout << n+2 << " " << n+3 << endl;
	if(n <= 3) return 0;
	
	for(int i = 1; i < n/4; i++){
		for(int j = 0; j < 3; j++){
			cout << i*4+j << " " << i*4+j+1 << endl;
			cout << n+i*4+j << " " << n+i*4+j+1 << endl;
		}
		cout << n+(i-1)*4+3 << " " << i*4 << endl;
		cout << i*4+3 << " " << n+i*4 << endl;
	}
	
	llint x = n/4*4;
	if(n%4 == 0){
		llint mul = 1;
		for(; mul <= x; mul *= 2);
		mul /= 2;
		cout << mul << " " << x << endl;
		cout << x-mul+1 << " " << n+x << endl;
		return 0;
	}
	if(n%4 >= 1){
		cout << 1 << " " << x << endl;
		cout << x << " " << x+1 << endl;
		cout << 1 << " " << n+x+1 << endl;
		cout << n+x+1 << " " << n+x << endl;
	}
	if(n%4 >= 2){
		cout << 2 << " " << x+2 << endl;
		cout << n+x+1 << " " << n+x+2 << endl;
	}
	if(n%4 >= 3){
		cout << 2 << " " << x+3 << endl;
		cout << x << " " << n+x+3 << endl;
	}
	
	return 0;
}
