#include <bits/stdc++.h>
using namespace std;

#define int long long
#define forn(i,a,n) for (int i=a; i<n; i++)

int cnt[2001];

signed main(){
	ios::sync_with_stdio(false);
   	cin.tie(0);

	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	int n;
	cin>>n;
	cnt[1]=cnt[2]=0;
	cnt[3]=cnt[4]=cnt[5]=1;
	cnt[6]=2;
	forn(i,7,n+1)
		cnt[i]=(cnt[i-1]+cnt[i-3])%1000000007;
	cout<<cnt[n]<<endl;
	return 0;
}