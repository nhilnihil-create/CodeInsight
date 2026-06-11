#include <bits/stdc++.h>

using namespace std;

#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl "\n"
#define dump(x) cerr << "~ " << #x << " = " << x << endl


int main() {

	fast_cin;
	
	int ar[] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

	int n;
	cin >> n;

	cout << ar[n-1] << endl;
	
	
	
	return 0;
}