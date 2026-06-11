#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define setbits(x) __builtin_popcount(x)
#define zerobits(x) __builtin_ctz(x)
#define setbitsll(x) __builtin_popcountll(x)
#define zerobitsll(x) __builtin_ctzll(x)
#define inf 1e18
#define ps(x,y) fixed<<setprecision(y)<<x

typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef unsigned long long ull;
typedef map<int,int> mii;

const int MOD = 1e9+7;
const int maxN = 2e5+1;
int arr[maxN];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,k;
	cin >> n >> k;
	for (int i = 0;i < n;++i) {
		cin >> arr[i+1];
		arr[i+1] += arr[i];
	}
	int ans = 0;
	for (int i = k;i <= n;++i) {
		ans = max(ans,arr[i]-arr[i-k]);
	}
	double x = (double)(ans+k)/2.0;
	cout << ps(x,9) << '\n';
	return 0;
}

