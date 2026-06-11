#include <bits/stdc++.h>
using namespace std;
int main(){
	string S;
	int n;
	cin >> n >> S;
	int count = 0;
	for(int i = 2; i < n; i++){
		if(S[i - 2] == 'A' && S[i - 1] == 'B' && S[i] == 'C'){
			count++;
		}
	}
	cout << count << endl;
}		


