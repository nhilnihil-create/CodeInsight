#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define reverse(x) reverse(x.begin(), x.end())
#define sort(x) sort(x.begin(), x.end())
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long,long long>
#define f first
#define s second
typedef long long ll;
const int mod = 1e9+7;
using namespace std;
int n, m;

int main(){
	int i, j;
	ll ans;
	cin >> n;
	if(n == 1)ans = 0;
	else if(n==2)ans = 1;
	else {
		ans = (ll)(n-1)*n/2;
	}
	cout << ans;
	return 0;
}
