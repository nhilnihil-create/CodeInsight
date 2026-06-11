#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int N , R, ir;
	cin >> N >> R;
	if (N >= 10) {
		ir = R;
	}
	else {
		ir = 100*(10 - N) + R;
	}
	cout << ir << endl;

}