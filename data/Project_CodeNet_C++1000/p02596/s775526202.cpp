#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
	int k;
	cin >> k;
	int rm = 0;
	if(k%7==0) k/=7;
	for(int i = 1; i < 1000000; i++){
		rm = rm * 10 + 1;
		rm%=k;
		if(rm == 0){
			cout << i;
			return 0;
		}
	}
	cout << "-1";
	return 0;
}
