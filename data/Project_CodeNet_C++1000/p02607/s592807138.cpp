#include<bits/stdc++.h>
using namespace std;
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);cout.tie(NULL);
        int n,a,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
                cin>>a;
                if(i%2==1 && a%2==1){
                        ans++;
                }
                
        }
        cout<<ans;
        return 0;
}
/*

        creation time:  13.09.2020 09:23:27

*/                      

