#include <bits/stdc++.h>
#define PI 3.141592653589793
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	int i,j;
	int ans=0;
	int ctr=0;

	cin >> N;

	if(N%2)
		ans=N/2+1;
	else
		ans=N/2;

	cout << ans << endl;

	return 0;
}

