#include<bits/stdc++.h>
#define int long long
#define REP(i,a,n) for(int i=a;i<(n);i++)
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n,x,a,cnt0,cnt1,ans=1;
	cnt0=0;
	cin>>n>>x;
	REP(i,0,n){
		cin>>a;
		cnt1=a+cnt0;
		cnt0=cnt1;
		if(cnt1<=x)ans++;
	}
	cout<<ans<<endl;
    return 0;
}
