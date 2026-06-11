#include <bits/stdc++.h>
using namespace std;

signed main(){
	vector<char> S(4);
	for(int i = 0; i < 4; i++){
		scanf("%c", &S[i]);
	}
	sort(S.begin(), S.end());
	if(S[0] == S[1] && S[1] != S[2] && S[2] == S[3]){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}