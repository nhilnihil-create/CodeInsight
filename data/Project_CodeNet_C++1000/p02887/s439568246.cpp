#include <bits/stdc++.h>

using namespace std;

int main() {
int n;
string S;
cin >> n >> S;
string res;
for(int i = 0; i < n; i++){
	if(res.empty()){
		res += S[i];
	} else {
		if(S[i] != res[res.size()-1]){
			res += S[i];
		}
	}
}
cout << res.size() << endl;
}
