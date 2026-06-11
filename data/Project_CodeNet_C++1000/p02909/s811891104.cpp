#include <bits/stdc++.h>
using namespace std;

signed main(){
	string S;
	string T[3] = {"Sunny", "Cloudy", "Rainy"};
	cin >> S;
	for(int i = 0; i < 3; i++){
		if(S == T[i]){
			cout << T[(i + 1) % 3] << endl;
			return 0;
		}
	}
}