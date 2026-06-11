#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define long long long
typedef pair<int,int> ii;

int main()
{
	// freopen("input.in", "r", stdin);

	int n, k;
	cin >> n >> k;
	if(k == 1) cout << "0\n";
	else cout << n-k << "\n";
}