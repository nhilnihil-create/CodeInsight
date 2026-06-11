#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
const int MOD = 1e9+7;
const int MOOD = 998244353;
#define PI 3.14159265359
typedef long long ll;
using namespace std;


int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	vector<ll> asum(n+1);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		asum[i+1] = a[i] + asum[i];
	}
	vector<ll> asummod(n+1); 
	for (int i = 1; i <= n; i++){
		if ((asum[i]-i)%k < 0){
			asummod[i] = (asum[i]-i)%k + k;
		}else{
			asummod[i] = (asum[i]-i)%k;
		}
	}
	map<int, ll> mp;
	for (int i = 0; i < min(k, n+1); i++){
		mp[asummod[i]]++;
	} 
	ll ans = 0;
	for (auto x : mp){
		ans += x.second*(x.second-1)/2;
	}
	if (k < n){
		for (int i = 0; i <= n-k; i++){
			mp[asummod[i]]--;
			ans += mp[asummod[k+i]];
			mp[asummod[k+i]]++;
		}
	}
	cout << ans << endl;
	return 0;
}
