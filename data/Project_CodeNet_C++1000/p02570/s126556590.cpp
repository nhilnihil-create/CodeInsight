#include <bits/stdc++.h>
#define PI 3.141592653589793
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int D,S,T;
	int i,k;
	int ans=0;
	int ctr=0;

	cin >> D >> S >> T;

	if(D<=S*T)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}

