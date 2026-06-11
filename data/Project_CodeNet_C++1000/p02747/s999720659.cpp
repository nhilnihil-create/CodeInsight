#include <bits/stdc++.h>
using namespace std;
int main() {
	string s; cin >> s;
  	bool w = s.length() % 2 == 0;
  	char c[] = {'h', 'i'};
  	for (int i = 0; i < s.length(); i++) {
    	w &= c[i%2] == s[i]; 
    }
  	cout << (w ? "Yes" : "No") << endl;
}