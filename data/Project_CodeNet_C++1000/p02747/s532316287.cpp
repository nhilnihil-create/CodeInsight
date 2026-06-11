#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
  	cin >> s;
  	if (s.length() % 2) {
        cout << "No";
        return 0;

  	}
  	long long h = 0, i = 0;
  	for (int i = 0; i < s.length(); i++) {
		if (i % 2) {
        	if (s[i] != 'i') {
             	cout << "No";
              return 0;
            }
        } else {
          if (s[i] != 'h') {
             	cout << "No";
              return 0;
            }
        }
    }
  cout << "Yes";
}
