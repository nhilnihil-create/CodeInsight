#include "bits/stdc++.h"
using namespace std;

int main() {
	int P,Q,R;
	cin >> P >> Q >> R;
	int sum = P+Q+R;
	cout << sum -max(P,max(Q,R))<<endl;
	return 0;
}