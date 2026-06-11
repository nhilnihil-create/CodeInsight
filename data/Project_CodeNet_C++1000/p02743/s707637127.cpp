#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<int(n);i++)
using namespace std;
int main() {
	long long a,b,c;

	cin >>a>>b>>c;
	string ans ="No";
	if ((c-a-b)>0&&4*a*b<(c-a-b)*(c-a-b)) ans="Yes";
	cout << ans<<endl;
	return 0;
}
