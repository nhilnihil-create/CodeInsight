#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i,a,n) for (int i=a; i<n; i++)

signed main(){
	ios::sync_with_stdio(false);
   	cin.tie(0);

	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int a,b,c;
	cin>>a>>b>>c;
	if (c-a-b>0 && 4*a*b<(c-a-b)*(c-a-b))
		cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}