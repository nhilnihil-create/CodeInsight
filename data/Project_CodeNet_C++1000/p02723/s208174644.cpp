/*
* AUTHOR : Haoyang(Max) Chen
* INSTITUTION : Australian National Unversity
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;
	if (input[2] == input[3] && input[4] == input[5]) {
		cout << "Yes" << "\n";
	}else {
		cout << "No" << "\n";
	}


	return 0;
}
