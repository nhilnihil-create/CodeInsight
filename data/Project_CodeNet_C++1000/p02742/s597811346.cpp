#include <bits/stdc++.h>

using namespace std;

int main(){
	long long int n, m;
	cin >> n>> m;
	long long int sum = n*m;
	if(n > 1 && m > 1)
		(sum % 2 == 0)?cout << sum/2:cout << sum/2 + 1;
	else cout << 1;
}


