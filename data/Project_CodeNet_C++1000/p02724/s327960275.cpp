#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main()
{
	int x;
	cin >> x;
	int happyness = 0;
	happyness += (x / 500) * 1000;
	x = x % 500;
	happyness += (x / 5) * 5;
	x = x % 5;
	cout << happyness << endl;
	return 0;
}
