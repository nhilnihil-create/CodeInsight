#include <bits/stdc++.h>
using namespace std;

signed main(){
	string S, T;
	cin >> S >> T;
	printf("%d\n", (S[0] == T[0]) + (S[1] == T[1]) + (S[2] == T[2]));
	return 0;
}