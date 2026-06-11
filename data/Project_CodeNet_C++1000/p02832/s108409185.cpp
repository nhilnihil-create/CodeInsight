#include<bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	int i = 0;
	int j = 1, res = 0;;
	while (i < n)
	{
		if(a[i] == j) {
			j++;
			res++;
		}
		i++;
	}

	if(res == 0) cout << "-1" << endl;
	else cout << n - res << endl;

	return 0;
}
