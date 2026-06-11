#include <bits/stdc++.h>
using namespace std;

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    long long int ans=0;
    for(int i=1;i<=n;++i)
    {
        if(i%3!=0 && i%5!=0)
        {
            ans+=i;
        }
    }
    cout<<ans<<endl;
  	
   // cout<<ans<<endl;
	return 0;
}