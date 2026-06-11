// A- Sum of Two Integers

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;


	int counter = 0;
	if(n % 2 == 1){
		for(int i = 1; i <= n / 2; ++i){
			if(n - i > 0) ++counter;
		}
	}
	else{
		for(int i = 1; i < n / 2; ++i){
			if(n - i) ++counter;
		}
	}

	cout << counter << "\n";

	return 0;
}