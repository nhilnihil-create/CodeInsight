#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,k;
	cin >> n >> k;
	cout << min(abs(n%k-k),n%k) << endl;
	return 0;
}
