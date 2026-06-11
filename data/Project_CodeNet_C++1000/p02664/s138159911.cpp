#include <bits/stdc++.h>
using namespace std;

int main() {
	string t;
	cin >> t;
    for (int i=0; i<(int)t.size(); i++){
      if (t.at(i)=='?')
        t.at(i)='D';
    }
	cout << t << endl;
}