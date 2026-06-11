#include <bits/stdc++.h>
using namespace std;

int main(){

	int k, ans = 0, num = 0;
	cin >> k;

	vector<int>  v(k,0);

	do{
		num = num*10 + 7;
		num = num%k;
		ans++;
				
		if (v[num])
		{
			cout << -1 << "\n";
			return 0;
		}
		else v[num] = 1;
	} while (num);

	cout << ans << "\n";
	return 0;
}