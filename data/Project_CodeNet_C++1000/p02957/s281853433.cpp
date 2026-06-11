#include <bits/stdc++.h>
using namespace std;

int main(){
	long long a,b;
	cin >> a >> b;
	if((b-a) & 1 ^ 1){
		cout << a + (b-a)/2;
	} else{
		cout << "IMPOSSIBLE";
	}
}
