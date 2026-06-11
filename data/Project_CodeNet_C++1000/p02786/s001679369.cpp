#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)

using namespace std;

long long dfs(long long X) {
	if(X == 1) {
		return 1;
	}
	return 2 * dfs(X/2) + 1;
}

int main(){
	long long X;
	cin >> X;
	cout << dfs(X) << endl;
}