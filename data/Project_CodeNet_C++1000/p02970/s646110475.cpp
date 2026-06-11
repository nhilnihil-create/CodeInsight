#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;

const ll mod = 1000000007;


int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
	int n, d; cin >> n >> d;
	int num = 2 * d + 1;
	if(n % num == 0) cout << n/num << endl;
	else cout << n / num + 1 << endl;
} 