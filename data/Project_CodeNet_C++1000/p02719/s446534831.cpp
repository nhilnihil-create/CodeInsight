#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define INF 100000000000
typedef long long ll;

int main() {
	ll n, k, comp;
	cin >> n >> k;
	if (n >= k) {
		ll a = n / k;
		n = n % (a * k);
	}
	
	if (n < k && n != 0) {
		comp = k - n;
		while (abs(k - comp) < comp) {
			comp = abs(k - comp);
		}
		n = comp;
	}
	cout<<n;
}