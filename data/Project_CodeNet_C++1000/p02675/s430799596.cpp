#include <bits/stdc++.h>
#include <algorithm>  
#include <unordered_set>

#define ll long long

using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll N;
	cin >> N;

	int d = N % 10;

	switch (d) {
	case 2:
	case 4:
	case 5:
	case 7:
	case 9:
		cout << "hon" << endl;
		break;
	case 0:
	case 1:
	case 6:
	case 8:
		cout << "pon" << endl;
		break;
	case 3:
		cout << "bon" << endl;
		break;
	}

	

	return 0;
}