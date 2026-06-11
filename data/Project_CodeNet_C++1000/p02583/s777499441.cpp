#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#include<numeric>
#include<list>
#include<cmath>
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0])
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

using namespace std;
typedef long long ll;
//using P = pair<int, int>;


int main(void) {
	int n,l;
	cin >> n;
	vector<ll> vec(n);
	int ans = 0;

	if(n)
	rep(i, n) {
		cin >> l;
		vec[i] = l;

	}
	sort(vec.begin(), vec.end());

	for (ll i = 0; i < n-2; i++) {
		for (ll j = i+1; j < n-1; j++) {
			for (ll k = j+1; k < n;k++) {
				if (vec[i] != vec[j]&& vec[j] != vec[k]&&(vec[i]+vec[j])>vec[k]  ){
					ans++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
