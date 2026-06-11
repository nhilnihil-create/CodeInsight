#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,a,las=0;
    scanf("%d",&n);
    cin>>las;
    long long ans=0;
    for(int i=2;i<=n;++i) {
        scanf("%d",&a);
        if(a<las) ans+=las-a;
        else las=a;
    }
    cout<<ans;
}