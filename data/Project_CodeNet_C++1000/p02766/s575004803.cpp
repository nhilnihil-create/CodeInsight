#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	int count = 0;
	cin >> n >> k;
	while (n != 0 ){
		count ++;
		n =  n / k;
	}
	cout << count;	
	return 0;
}

