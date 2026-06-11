#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

ll dp0[100001];
ll dp1[100001];

int main(){
	string s;
	cin >> s;
	
	dp1[0] = 2;
	dp0[0] = 1;
	for (int i = 1; i < s.length(); i++){
		if (s[i] == '1'){
			dp1[i] = dp1[i-1]*2%MOD;
			dp0[i] += dp1[i-1];
		}else{
			dp1[i] = dp1[i-1]%MOD;
		}
		dp0[i] += dp0[i-1]*3;
		dp0[i] %= MOD;
	}
	cout << (dp1[s.length()-1] + dp0[s.length()-1])%MOD<< endl;
	return 0;
}
