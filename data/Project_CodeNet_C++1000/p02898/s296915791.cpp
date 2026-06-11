#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
#define FastIO ios::sync_with_stdio(false), cin.tie(NULL);
#define all(x) x.begin(), x.end()
#define pb push_back
#define endl '\n'
typedef long long ll;


int main()
{
	FastIO;
	int n, k;
	cin >> n >> k;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp >= k) ans++;
	}
	cout << ans;
}
