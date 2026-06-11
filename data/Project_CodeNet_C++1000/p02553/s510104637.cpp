#include <iostream>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	t=1;
	while(t--)
	{
            long long int a,b,c,d;
            cin>>a>>b>>c>>d;
            
            long long int ans=-2e18;
            
            ans=max(ans,a*c);
            ans=max(ans,a*d);
            ans=max(b*c,ans);
            ans=max(ans,b*d);
            
            cout<<ans<<endl;
            
            
	   
	}
	   
	   
	return 0;
}