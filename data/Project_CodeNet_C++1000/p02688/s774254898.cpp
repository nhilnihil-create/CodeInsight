#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n,k;
    map<int,int>cnt;
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        int d;
        cin>>d;
        for(int j=1;j<=d;j++){
            int v;
            cin>>v;
            cnt[v]++;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(cnt[i]==0) ans++;
    }
    cout<<ans<<endl;
}

