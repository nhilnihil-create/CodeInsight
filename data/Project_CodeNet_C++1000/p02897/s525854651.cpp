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
	int n;
	cin >> n;
	int x = 0;
	for (int i = 1; i <= n; i++) {
		if (i & 1) x++;
	}
	cout << (double)x / n;
}
