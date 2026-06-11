#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

	string n;
	int s=0;
	cin >> n;
	for(auto c : n) {
		s+= c - '0';
	}
	if(s%9 == 0)
		cout << "Yes";
	else 
		cout << "No";

    return 0;
} 
 
