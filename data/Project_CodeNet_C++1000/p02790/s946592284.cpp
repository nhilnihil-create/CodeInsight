#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

const int MOD = 1000000007;
int main()
{
	int a, b, m = 0;
	cin >> a >> b;
	if(a > b){
		for(int i = 0; i < a; i++){
			cout << b;
		}
	}
	else {
		for(int i = 0; i < b; i++){
			cout << a;
		}
	}
	
	return 0;
}
