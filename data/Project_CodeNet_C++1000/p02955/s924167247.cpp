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

vector<ll> divisor;

void get_divisor(ll num){
	for (int i = 1; i*i <= num; i++){
		if (num % i == 0){
			divisor.push_back(i);
			if (num != i*i) divisor.push_back(num/i);
		}
	}
	return;
}

int main(){
	ll n, k, sum = 0;
	cin >> n >> k;
	vector<ll> a(n);
	for (int i = 0; i < n; i++){
		cin >> a[i];
		sum += a[i];
	}
	get_divisor(sum);
	sort(divisor.begin(), divisor.end());

	ll ans = 1;
	for (auto x : divisor){
		ll temp = 1000000000000000000;
		vector<ll> vec1, vec2;
		vector<ll> sum1(n+1), sum2(n+1);
		sum1[0] = 0, sum2[0] = 0;
		for (int i = 0; i < n; i++){
			vec1.push_back(a[i]%x);
			vec2.push_back(abs(a[i]%x-x));
		}
		sort(vec1.begin(), vec1.end());
		sort(vec2.begin(), vec2.end());
		for (int i = 0; i < n; i++){
			sum1[i+1] = sum1[i] + vec1[i];
			sum2[i+1] = sum2[i] + vec2[i];
		}
		for (int i = 1; i <= n; i++){
			if (sum1[i] == sum2[n - i]){
				temp = min(temp, sum1[i]);		
			}
		}
		if (temp <= k) ans = x;
	}
	cout << ans << endl;
	return 0;
}