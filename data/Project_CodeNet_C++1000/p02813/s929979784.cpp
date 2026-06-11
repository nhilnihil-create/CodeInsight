#include<bits/stdc++.h>
using namespace std;

int MOVE(int *a, int n){
    int i,j,k=n,cnt,ans,moves=0,s[10]={};
    for(i=1;i<=n;i++){
        cnt=0,ans=1;
        for(j=1;j<=*a;j++) if(s[j]==0) cnt++;
        s[*a]=1;
        for(j=1;j<k;j++) ans*=j;
        ans*=(cnt-1);
        moves+=ans,a++,k--;
    }
    return moves;
}

int main()
{
    int n,p1[10],p2[10];
    cin>>n;
    for(int i=0;i<n;i++) cin>>p1[i];
    for(int i=0;i<n;i++) cin>>p2[i];
    cout<<abs(MOVE(p1,n)-MOVE(p2,n));

}
