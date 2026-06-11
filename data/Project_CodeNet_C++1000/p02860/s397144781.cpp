#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using LL = long long;
using P = pair<int,int>;


int main(){
	int N;
	cin >> N;
	string S;
	cin >> S;
	if(S.substr(0,N/2) == S.substr(N/2)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}










