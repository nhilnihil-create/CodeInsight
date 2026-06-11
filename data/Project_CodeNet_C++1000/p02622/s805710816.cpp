#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	string n;
	cin >> s >> n;
	int count = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] != n[i]){
			count++;
		}
	}
	cout << count << endl;
	return 0;
}
