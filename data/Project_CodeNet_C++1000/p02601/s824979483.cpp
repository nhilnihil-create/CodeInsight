#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	int a,b,c,k;
	cin >> a >> b >> c >> k;
	int count = 0;
	while(a >= b){
		b *= 2;
		count++;
	}
	while(b >= c){
		c *= 2;
		count++;
	}
	if(count <= k) cout << "Yes" << endl;
	else cout << "No" << endl;
    return 0;
}