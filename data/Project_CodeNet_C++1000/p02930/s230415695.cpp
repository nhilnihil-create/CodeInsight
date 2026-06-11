// D - Classified
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int l = 0, k = (i ^ j) & -(i ^ j);
			for ( ; k; k >>= 1) l++;
			cout << l << ' ';
		}
		cout << endl;
	}

	return 0;
}
