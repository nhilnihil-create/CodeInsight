
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define vi vector<int>
#define INF 1000000000

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	set<string> items;
	int n; cin >> n;
	string item;
	while(n--){
		cin >> item;
		items.insert(item);
	}	

	cout << items.size() << endl;

	return 0;
}
