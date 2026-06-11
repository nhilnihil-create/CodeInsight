#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	if(n % 1000 == 0){
		cout << 0;
	}
	else{
		for(int i = 1; i < 10001; i++){
			if((i + n) % 1000 == 0){
				cout << i;
				break;
			}
		}
	}
}
