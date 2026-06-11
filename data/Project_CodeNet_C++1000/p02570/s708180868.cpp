#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

int t,n,m;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	double d,t,sp;
	cin >> d >> t >> sp;
	if (d/sp < t+1e-9) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
