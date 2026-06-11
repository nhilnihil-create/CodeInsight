#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    string n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n.size(); i++)
        sum += n[i] - '0';
    if (sum % 9 == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

	return 0;
}