#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
  	string s;
  	cin >> s;
  	bool triggered = false;
  	for (int i = 0; i < s.length(); i++) {
      	if (i % 2 == 0 && (s[i] == 'L')) {
      		cout << "No";
          	triggered = true;
          	break;
        } else if (i % 2 == 1 && s[i] == 'R') {
          	cout << "No";
          	triggered = true;
          	break;
        }
    }
  	if (!triggered) {
      	cout << "Yes";
    }
}