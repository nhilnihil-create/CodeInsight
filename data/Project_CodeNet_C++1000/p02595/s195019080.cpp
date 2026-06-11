#include<bits/stdc++.h>
using namespace std;
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);cout.tie(NULL);
        unsigned long long int n,d,x,y,ans=0;
        cin>>n>>d;
        while(n--){
                cin>>x>>y;
                if(x*x+y*y<=d*d){
                        ans++;
                }
        }
        cout<<ans;
        return 0;
}
/*

        creation time:  13.09.2020 09:23:27

*/                      

