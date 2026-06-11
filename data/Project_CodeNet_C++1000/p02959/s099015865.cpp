#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <complex>
#include <iomanip>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <cstring>

#define ll long long
#define ld long double
#define HS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define INF 0x3f3f3f3f3f3f3f3f
#define point complex <double> 
#define pi acos(-1)
#define mod 1000000007


using namespace std;
ll arr[200005],brr[200005];


int main() {
	HS
		int n;
	cin >> n;
	for (int i = 0; i < n+1; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
		cin >> brr[i];
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		
		if (arr[i] <= brr[i])
		{
			ans += arr[i];
			brr[i] -= arr[i];
		}
		else
		{
			ans += brr[i];
			brr[i] = 0;
		}
		if (brr[i] && arr[i + 1] - brr[i] >= 0)
		{
			ans += brr[i];
			arr[i + 1] -= brr[i];
			brr[i] = 0;
		}
		else if (brr[i] && arr[i + 1] - brr[i] < 0)
			ans += arr[i + 1], arr[i + 1] = 0;
		//cout << arr[i] << " " << brr[i] << " " << ans << endl;

	}
	cout << ans << endl;

	return 0;
}