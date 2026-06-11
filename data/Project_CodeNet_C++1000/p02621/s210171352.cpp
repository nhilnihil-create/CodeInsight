#include "bits/stdc++.h"
using namespace std;
using lint = int64_t;
int main(){

	string A; cin >> A;
	lint a = stoll(A);
	cout << (a+a*a+a*a*a) << endl;
}
