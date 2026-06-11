#include <bits/stdc++.h>
#define PI 3.141592653589793
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int H,N;
	int i,k;
	int ans=0;
	int ctr=0;

	cin >> H >> N;

	 
	vector<int> gv(N);
	rep(i,N) cin >> gv[i];

	if(H<=accumulate(gv.begin(),gv.end(),0)) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}

