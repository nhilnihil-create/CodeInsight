//#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#define sz(v) (int)v.size()
#define ll long long
#define ull unsigned long long
using namespace std;
const int PI = 3.14159265;
void fast() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
}
int main()
{
	//freopen("file.in","r",stdin);
	//freopen("file.out","w",stdout);
	fast();

	int n, p[1001];
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		if (i % 2 == 0 && p[i] % 2 == 1) {
			cnt++;
		}
	}
	cout << cnt << '\n';
	return 0;
}
