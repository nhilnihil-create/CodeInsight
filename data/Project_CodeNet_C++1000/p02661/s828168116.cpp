#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const long long INFL = 2e18;
const int MOD = 1000000007;
int main(){
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> b(n);
	for(int i = 0;i < n;i++)cin >> a[i] >> b[i];

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	if(n % 2 == 1){
		cout << b[n/2] - a[n/2] + 1 << endl;
	}
	else{
		ll ans = 0;
		ll l = (a[n/2] + a[n/2-1] + 1) / 2,r = (b[n/2] + b[n/2-1] + 1) / 2 - 1;
		if((a[n/2] + a[n/2-1]) % 2 == 1)ans++;
		if((b[n/2] + b[n/2-1]) % 2 == 0)ans++;
		cout << (r - l + 1) * 2 + ans << endl;
	}
}
