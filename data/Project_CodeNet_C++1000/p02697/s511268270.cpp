#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k, low, up;

int main(){
    cin >> n >> k;
	low = k - k / 2;
	up = k / 2;
	for(ll i = 1; i <= low; i++){
		cout << i << " " << ( 2 * low ) - i + 1 << '\n';
	}
	for(ll i = 1; i <= up; i++){
		cout << low * 2 + i << " " << 2 * ( low + up + 1 ) - i << '\n';
	}
}