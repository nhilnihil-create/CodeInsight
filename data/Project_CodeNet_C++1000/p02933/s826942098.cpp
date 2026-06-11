/*A - Red or Not*/

#include <bits/stdc++.h>

using namespace std;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string cad;
	int num;

	cin >> num;
	cin >> cad;

	if(num >= 3200)
		cout << cad;
	else
		cout << "red";

	return 0;
}
