#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ll H, N;
	cin >> H >> N;

	ll damage = 0;
	for(int i = 0 ; i < N ; i++){
		int a;
		cin >> a;
		damage += a;
	}
	if(damage >= H)
		cout << "Yes";
	else cout << "No";
	cout << '\n';
	return 0;

}