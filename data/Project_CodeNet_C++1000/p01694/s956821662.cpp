#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <cctype>
#include <complex>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <cassert>
#include <iomanip>

using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
typedef complex<int> P;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const double PI = acos(-1.0);


bool solve(){
	int n;
	cin>> n;
	if(!n) return false;

	int ans = 0;
	bool to_up = true;
	bool l = false, r = false;
	for(int i=0;i<n;i++){
		string str;
		cin>> str;
		if(str.front() == 'l') l ^= true;
		if(str.front() == 'r') r ^= true;
		if((str.back() == 'u' && l && r && to_up)
			|| (str.back() == 'd' && !l && !r && !to_up)){
			to_up ^= true;
			ans++;
		}
	}
	cout<< ans<< endl;
	return true;
}

int main(){
	cout.setf(ios::fixed); cout.precision(10);
	while(solve());
	return 0;
}