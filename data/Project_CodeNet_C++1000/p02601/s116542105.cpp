#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

int a, b, c, d;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> c >> d;
	for(int i = 0; i <= d; i++)
		for(int j = 0; j <= d - i; j++)
			for(int k = 0; k <= d - i - j; k++)
				if(a * (1 << i) < b * (1 << j) && b * (1 << j) < c * (1 << k)){
					cout << "Yes\n";
					return 0;
				}
	cout << "No\n";
	return 0;
}