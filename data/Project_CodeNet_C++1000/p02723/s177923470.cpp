#include<bits/stdc++.h>
using namespace std;
long long pi = 3.14159265358979323846264338327;
string s;
int main() {
	cin >> s;
	if(s.at(2) == s.at(3) && s.at(4) == s.at(5)){
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
 	return 0;
}
