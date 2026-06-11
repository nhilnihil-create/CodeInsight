#include<bits/stdc++.h>
#define pb           push_back
#define pf           push_front
#define in           insert
#define ff           first
#define ss           second
#define int          long long
#define rep(i,x,m)   for(int i=x;i<m;i++)
#define MOD          1000000007
#define endl         "\n"
#define all(v)       v.begin(),v.end()
#define rall(v)      v.rbegin(),v.rend()
#define vi           vector<int>
#define pi           pair<int,int>
#define sz(x)       (int)x.size()
#define pq           priority_queue<int>
#define fix(y)       fixed<<setprecision(y)
#define print(v)     for(int i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl
#define FIO         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int power(int n,int m)
{int p=1;if(m==0)return 1;p=(power(n,m/2)%MOD);p=(p%MOD*p%MOD)%MOD;
return(m&1?((p%MOD*n%MOD)%MOD):(p%MOD));}


void solve()
{
     int n;
     cin>>n;
     int a[n+1],b[n];
     rep(i,0, n+1)cin>>a[i];
     rep(i,0,n)cin>>b[i];
     int sum=0;
     rep(i,0,n)
     {
        //cout<<i<<":"<<" ";
        sum+=min(a[i],b[i]);
        //a[i]-=min(a[i],b[i]);
        b[i]-=min(a[i],b[i]);
        sum+=min(b[i],a[i+1]);
        a[i+1]-=min(b[i],a[i+1]);
        //cout<<sum<<endl;

     }
     cout<<sum<<endl;

}

signed main()
{
        FIO
       
        
        int t=1;
        //cin>>t;
        while(t--)
        solve();
        cerr<<(float)clock()/CLOCKS_PER_SEC*1000<<" ms"<<endl;

        return 0;
}