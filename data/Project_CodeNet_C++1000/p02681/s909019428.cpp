#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	string S, T;
	cin >> S >> T;
	if (T.substr(0,S.size()) != S) cout << "No" << endl;
	else cout << "Yes" << endl;

return 0;
}
