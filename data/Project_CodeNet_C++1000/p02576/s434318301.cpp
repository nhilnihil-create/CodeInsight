#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,x,t;
	int ans;
	scanf("%d %d %d",&n,&x,&t);
	if (x>=n) cout<<t<<endl;
	else {
		ans=n%x==0?t*n/x:t*(n/x+1);
		cout<<ans<<endl;
	}
	return 0;
}