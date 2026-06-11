#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pow5(int n){
	return (ll)n*n*n*n*n;
}

int main(){
	ll x;
	cin >> x;
	for(int i = -1000; i<= 1000; i++){
		for(int j = -1000; j<= 1000; j++){
			if(pow5(i) - pow5(j) == x){
				cout << i << " " << j;
				return 0;
			}
		}
	}
	return 0;
} 