#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define mt make_tuple
#define MOD 1000000007
#define fo(i,a,b) for(i=a;i<b;i++)
#define foe(i,a,b) for(i=a;i<=b;i++)
#define all(x) x.begin(), x.end()
#define vi vector<int>
#define vl vector <long long int>
#define pii pair <int,int>
#define pll pair <long long int, long long int>
#define vpii vector< pair<int,int> >
#define vpll vector < pair <long long int,long long int> >
#define boost ios::sync_with_stdio(false); cin.tie(0)
using namespace std;
const int inf = 1e9 + 5;
const ll inf64 = 1e18 + 5;

bool chk(int arr[], int n, int mid, int k)
{
	ll res = 0;
	for(int i = 0; i < n; i++) 
	res += (arr[i] - 1) / mid;
	return (res <= k);
}
int main()
{
	boost;
	int n, k, i;
	cin >> n >> k;
	int arr[n];
	fo(i, 0, n)
	cin >> arr[i];
	
	int f = 1, l = inf, mid, ans = inf;
	while(f <= l) {
		mid = (f + l) / 2;
		if(chk(arr, n, mid, k)) {
			ans = min(ans, mid);
			l = mid - 1;
		}
		else
		f = mid + 1;
	}
	cout << ans;
}
