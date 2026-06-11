#include <bits/stdc++.h>
#define PI 3.141592653589793
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;

int main(void){
	int N;
	int i,k;
	int ans=0;
	int ctr=0;
	string S;

	cin >> N >> S;

	vector<char> gv(S.length());
	rep(i,S.length()) gv[i]=S[i]-'A';

	rep(i,S.length()){
		printf("%c",((gv[i]+N)%26)+'A');
	}
	printf("\n");

	return 0;
}

