#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define INF (int)1e18
#define all(v) v.begin(), v.end()


int32_t main(){
    ios_base::sync_with_stdio(false),cin.tie(),cout.tie();
    // If you hack my code, you are gay
    int n;
    cin>>n;
    int ara[n];
    for(int i=0;i<n;i++){
        char x;
        cin>>x;
        ara[i]=(x=='R')?1:(x=='G')?2:3;
    }
    int suf[4][n+1];
    memset(suf,0,sizeof(suf));
    for(int i=n-1;i>=0;i--){
        suf[ara[i]][i]++;
        for(auto x:{1,2,3}) suf[x][i]+=suf[x][i+1]; 
    }
    int ans=0;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++)if(ara[i]!=ara[j]){
            ans+=suf[ara[i]^ara[j]][j+1]-(2*j-i<n && ara[2*j-i]==(ara[i]^ara[j]));
        }
    }
    cout<<ans;
    return 0;
}