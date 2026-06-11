#include<bits/stdc++.h>
using namespace std;
signed main(){
	long long n,k;
	cin >> n >> k;
	if(k<=1){
		cout << "0";
		return 0;
	}
	cout << n-k;
}