#include <iostream>
#include<string>
#include<vector>
#include <climits>
using namespace std;

int main() {
	string longW,shortW;
	int a, b, c,ans=INT_MAX;
	cin >> longW >> shortW;
	a = longW.size();
	b = shortW.size();
	c = a - b;
	for (int i=0;i<=c;i++) {
		int d = 0;
		for (int j=0;j<shortW.size();j++) {
			d+=(longW.at(i+j)!=shortW.at(j));
		}
		ans = min(ans, d);

	}
	cout << ans << endl;
	
}
