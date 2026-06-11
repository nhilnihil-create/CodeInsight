#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main() {
	int n;
	cin >> n;
	int out = 0;
	for(int a = 1; a <= n; a++){
		out += (n - 1) / a;
	}
	cout << out << endl;
}
