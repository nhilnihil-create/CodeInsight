#include<iostream>
#include<cstdio>
#include<cstring>
#include <cstdlib>  
#include <math.h>
#include <cmath>
#include<cctype>
#include<string>
#include<set>
#include<iomanip>
#include <map>
#include<algorithm>
#include <functional>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<bitset>
#include <deque>
#include <climits>
#include <typeinfo>
#include <utility> 
using namespace std;
using ll = long long;
template<typename T>using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
const ll inf = 1LL << 60;
#define all(x) (x).begin(),(x).end()
#define puts(x) cout << x << endl
#define rep(i,m,n) for(ll i = m;i < n;++i)
#define pb push_back
#define fore(i,a) for(auto &i:a)
#define rrep(i,m,n) for(ll i = m;i >= n;--i)


ll mod = 1000000007;
ll factorial[101010];
int main() {
	int N;
	string S;
	cin >> N >> S;
	factorial[0] = 1;
	for (int i = 1; i <= N; i++) {
		factorial[i] = i * factorial[i - 1];
		factorial[i] %= mod;
	}


	ll ans = 1;
	int cnt = 0;
	for (int i = 0; i < 2*N; i++) {
		if (cnt % 2) {
			if (S[i] == 'W')cnt++;
			else {
				ans *= cnt;
				cnt--;
			}
		}
		else {
			if (S[i] == 'W') {
				ans *= cnt;
				cnt--;
			}
			else cnt++;
		}
		ans %= mod;
	}
	if (cnt != 0)ans = 0;
	ans *= factorial[N];
	ans %= mod;
	puts(ans);

	return 0;
}