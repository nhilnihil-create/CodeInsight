#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int n;
	cin >> n;
	if(n == 1) cout << fixed << setprecision(9) << 1.00000000 << endl;
	else{
		int odd = (n+1)/2;
		double ans = double(odd)/double(n);
		cout << fixed << setprecision(9) << ans << endl;
	}
}