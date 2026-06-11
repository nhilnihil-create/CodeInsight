#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn = 500100;

ll cnt;
ll n, a, b;

int main() {
	cin>>n;

	ll result = 0LL;
	for(int i=1;i<=n;i++) {
		result += i * (n - i + 1);
	}
	for(int i=0;i<n-1;i++) {
		cin>>a>>b;
		if(a > b) swap(a, b);
		result -= a * (n - b + 1);
	}
	cout<<result<<"\n";
}