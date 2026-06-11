#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int l,n,sum=0,mini=INT_MAX;
	cin>>n>>l;
	for(int i=0;i<n;i++){
		int flavor=l+i;
		if(abs(mini)>abs(flavor))mini=flavor;
		sum+=flavor;
	}
	cout<<sum-mini;
    return 0;
}

