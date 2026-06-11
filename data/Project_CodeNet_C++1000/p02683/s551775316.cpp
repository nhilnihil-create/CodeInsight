#include<bits/stdc++.h>
using namespace std;
int main(){
        int n,m,x; cin>>n>>m>>x;
        int c[n]; int a[n][12],mi=0x3f3f3f3f;
        for(int i=0;i<n;i++){
                cin>>c[i];
                for(int j=0;j<m;j++) cin>>a[i][j];
        }
auto val=[&](int curr,int n,int m,int a[][12],int c[],int x){ int res=0; vector<int> dp(m,0); for(int i=0;i<n;i++){ if(curr&(1<<i)){ res+=c[i]; for(int j=0;j<m;j++) dp[j]+=a[i][j]; } } for(int i=0;i<m;i++) if(dp[i]<x) return -1; return res; };
        for(int i=0;i<(1<<n);i++){ int res=val(i,n,m,a,c,x); if(res!=-1) { mi=min(mi,res); }}
        if(mi==0x3f3f3f3f) { cout<<-1<<endl; return 0;}
        cout<<mi<<endl;
        return 0;
}

