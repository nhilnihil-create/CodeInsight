#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	int d;
	int t;
	int s;

	cin >> d >> t >> s;

	if ((d+s-1)/s <= t)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}

