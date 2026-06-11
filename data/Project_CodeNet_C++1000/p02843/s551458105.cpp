#include <bits/stdc++.h>
#define int long long
using namespace std;



signed main()
{
    int x;
	cin>>x;
	int val[6]={100,101,102,103,104,105};
	
    vector<bool> dp(x+1,false);
    dp[0]= true;
    for(int i=0;i<6;i++){
        for(int j=1;j<=x;j++){
            if(j>=val[i]) dp[j]= dp[j] || dp[j-val[i]];
        }
    }
    
    if(dp[x]) cout<<"1";
    else cout<<"0";
    
	return 0;
}
