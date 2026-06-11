#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[11][11];
    int i,j,n,d,ans,chek,cnt=0;
    cin>>n>>d;
    for(i=0;i<n;i++){
        for(j=0;j<d;j++) cin>>a[i][j];
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            ans=0;
            for(int k=0;k<d;k++){
                ans+=((a[i][k]-a[j][k])*(a[i][k]-a[j][k]));
            }
            chek=sqrt(ans);
            if(chek*chek==ans) cnt++;
        }
    }
    cout<<cnt;
}
