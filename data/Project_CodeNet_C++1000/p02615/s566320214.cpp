#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	int n;
	cin >> n;
	long long int sum = 0;
	vector <int> a(n);
	for (int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a.rbegin(),a.rend());
	sum += a[0];
	a.erase(a.begin());
	n-=2;
	while (n>=2){
		sum += *a.begin()*2;
		a.erase(a.begin());
		n -= 2;
	}
	if (n) sum += *a.begin();
	cout << sum << "\n";
	return 0;
}
