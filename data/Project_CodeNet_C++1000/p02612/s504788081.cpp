#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int N; cin >> N;
	int amt = ceil(N/1000.0);
	cout << amt*1000 - N << endl;
	return 0;
}
