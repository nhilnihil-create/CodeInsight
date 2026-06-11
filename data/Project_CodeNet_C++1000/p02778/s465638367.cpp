#include <bits/stdc++.h>
using namespace std;

int main() {
	string S;
	cin >> S;

	int sSize = S.size();
	string ans="";

	for(int i=0;i<sSize;i++){
		ans.push_back('x');
	}
	cout << ans << endl;
}
