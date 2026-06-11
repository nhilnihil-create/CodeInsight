#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, N) for(int i = 0; i < N; i++)
#define rep2(i, N, a, b) for(int i = a; i < N; i += b)

int main(){
	int X;
	cin >> X;

	if (X < 100) cout << 0 << endl;
	else if (X >= 2000) cout << 1 << endl;
	else if ((X / 100) * 5 >= X % 100) cout << 1<< endl;
	else cout << 0 << endl;
}