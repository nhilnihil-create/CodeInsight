#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(void){
	int N;
	cin >> N;
	int d[N];
	rep(i,N) cin >> d[i];
	sort(d,d+N);
	cout << d[N/2] - d[N/2-1] << endl;

	return 0;
}
