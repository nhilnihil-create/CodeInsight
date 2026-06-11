#include <bits/stdc++.h>
using namespace std;
#define oo 1000000010
#define mod 1000000007

int main(){
	int x;
	cin >> x;
	int cur = x * 360 / __gcd(x , 360);
	cout << cur / x << endl;	
	return 0;
}
