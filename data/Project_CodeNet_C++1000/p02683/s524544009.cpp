#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ll n,m,h;
    cin>>n>>m>>h;
    ll p[n+5],val[n+5][m+5];
    for(int i=0; i<n; i++){
        cin>>p[i];
        for(int j=0; j<m; j++){
            cin>>val[i][j];
        }
    }
    ll cnt=1;
    for(int i=1; i<=n; i++)
        cnt*=2;
    ll price=0,ans=1e18;
    for(int i=0; i<cnt; i++){
        ll test[m+5];
        for(int y=0; y<m; y++)
            test[y]=0;
        price=0;
        for(int j=0; j<n; j++){
            if((i & (1<<j))!=0){
                price+=p[j];
                for(int k=0; k<m; k++){
                    test[k]+=val[j][k];
                }
            }
        }
        bool flag=true;
        for(int x=0; x<m; x++){
            if(test[x]<h)
            {
                flag=false;
                break;
            }
        }
        if(flag){
            ans=min(ans,price);
        }
    }
    if(ans==1e18)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;

    return 0;

}
