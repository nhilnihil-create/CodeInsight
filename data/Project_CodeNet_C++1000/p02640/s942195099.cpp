#include <bits/stdc++.h>
using namespace std;
int main(){
	int x, n;
	cin >> x >> n;
	for(int i=0; i<=x; ++i){
		if(2*i+(x-i)*4 == n){
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
}
