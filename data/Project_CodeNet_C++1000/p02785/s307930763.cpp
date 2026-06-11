#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 200005;
ll H[MAX_N];

int main()
{
	int n,k;
	cin >> n >> k;
	rep(i,n)
	{
		cin >> H[i];
	}
	sort(H,H+n);
	ll sum = 0;
	rep(i,n-k)
	{
		sum += H[i];
	}
	cout << sum << endl;
	return 0;
}