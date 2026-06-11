#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	string S;
	cin >> N >> S;
	string ans = "No";
	if(N % 2 == 0){
		bool chk = true;
		for(int i=0;i<N/2;i++){
			if(S[i] != S[i + N / 2])chk = false;
		}
		if(chk) ans = "Yes";
	}
	cout << ans << endl;
}