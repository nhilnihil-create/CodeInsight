#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, x, t; 
int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> x >> t;
    cout << (n + (x - 1)) / x * t << endl;
	return 0;
}
