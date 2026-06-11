#include<bits/stdc++.h>
using namespace std;
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);cout.tie(NULL);
        int n,ans;
        cin>>n;
        if(n%1000==0){
                ans=0;
        }
        else{
                ans=1000-n+1000*(n/1000);
        }
        cout<<ans;
        
return 0;
}
/*

        creation time:  13.09.2020 09:23:27

*/                      

