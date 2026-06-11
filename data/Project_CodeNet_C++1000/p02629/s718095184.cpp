#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

int main() {
	ll n;
	cin >> n;
	ll t = n;
	ll m = 26;
	int cnt(0);
	while (t>0) {
		t = t - m;
		m *= 26;
		++cnt;
	}
	m /= 26;
	ll k = t + m;
	
	cnt--;
	k--;
	while (cnt>=0){
		ll aa = pow(26, cnt);
		int a = k / aa;
		cout <<char(a+97);
		k %= aa;
		cnt--;

	}
	return 0;
}