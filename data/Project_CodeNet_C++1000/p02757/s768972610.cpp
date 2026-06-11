#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <complex>
#include <stack>
#include <queue>
#include <unordered_map>
#include <set>
#include <deque>
#include <map>
#include <bitset>
#include <functional>
#include <cmath>

#define INF 10000000000
using namespace std;
using P = pair<long, long>;

const long long MOD = 1000000007;
int main(){
	long long n, p;
	cin >> n >> p;
	string s;
	cin >> s;
	
	long long ans = 0;
	if(p == 2){
		for(long long i = 0; i < n; i++){
			if((s[i]-'0')%2 != 0) continue;
			ans += (i+1);
		}
		cout << ans << endl;
	}else if(p == 5){
		for(long long i = 0; i < n; i++){
			if((s[i]-'0')%5 != 0) continue;
			ans += (i+1);
		}
		cout << ans << endl;
	}else{
		map<long long, long long> m;
		m[0]++;
		long long sum = 0;
		long long pow = 1;
		for(long long i = n-1; i >= 0; i--){
			sum += (s[i] - '0') * pow;
			sum %= p;
			m[sum]++;
			pow *= 10;
			pow %= p;
		}
		for(auto t : m){
			ans += (t.second - 1)*t.second / 2;
		}

		cout << ans << endl;
	}
}