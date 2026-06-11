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
        for(int j=1;j<=n;++j)
        {
            for(int k=1;k<=n;++k)
            {
                ans+=__gcd(__gcd(i,j),k);
            }
        }
    }
    cout<<ans<<endl;
  	
   // cout<<ans<<endl;
	return 0;
}