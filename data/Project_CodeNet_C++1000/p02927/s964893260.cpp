#include<bits/stdc++.h>
using namespace std;
int main() {
	int m, d; cin >> m >> d;
	int res = 0;
	for (int i = 1; i <= d; i++)
	{
		int x = i % 10, y = i / 10;
		if(x >= 2 && y >= 2){
			if(x * y <= m) res++;
		}
	}
	cout << res << endl;
	return 0;
}
