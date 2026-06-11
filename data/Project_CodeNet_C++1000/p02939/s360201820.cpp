#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	string S;
	cin >> S;

	char prev = ' ';
	int cnt = 0;
	bool two = false;
	rep(i, (int)(S.size())){
		if (two == true) two = false;
		else if (S[i] == prev){
			if (i == (int)(S.size()) - 1) break ;
			two = true;
			i++;
		}
		prev = S[i];
		cnt++;
	}
	cout << cnt << endl;
}