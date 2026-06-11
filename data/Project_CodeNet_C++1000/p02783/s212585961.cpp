#include <bits/stdc++.h>

using namespace std;
#define endl "\n"

const int MOD = 1000000007;
int main()
{
	int a, b, m = 0;
	cin >> a >> b;
	for(int i = a; i >0; i-=b){
		m++;
	}
	
	cout << m << endl;
	
	return 0;
}
