#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int n;
	cin >> n;
	vector<int> p(n);
	rep(i,n) cin >> p[i];
	int ans = 0;
	REP(i,n-2){
		int a = p[i-1];
		int b = p[i];
		int c = p[i+1];
		if((a < b && b < c) || (c < b && b < a)) ans++;
	}
	cout << ans << endl;
    return 0;
}

