#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	int N;
	cin >> N;
	int X[N];
	rep(i,N) cin >> X[i];
	sort(X,X+N);
	int p = 1e+6;
	for (int i = X[0]; i <= X[N-1]; i++) {
		int tmp = 0;
		rep(j,N) tmp += (X[j]-i)*(X[j]-i);
		p = min(tmp,p); 
	}
	cout << p << endl;

return 0;
}
