#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,x,n) for(int i=x;i<n;i++)
#define mod 1000000007 //10^9+7
#define INF 1000000000000 //10^12
#define F first
#define S second
#define P pair<int,int>
#define all(vec) vec.begin(),vec.end()
int n;
int a[300000];
int nl[300000],nr[300000];
int ans=0;
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i+a[i]<=n)nl[i+a[i]]++;
        if(i-a[i]>=1)nr[i-a[i]]++;
    }
    for(int i=1;i<=n;i++){
        ans+=nl[i]*nr[i];
    }
    cout<<ans<<endl;
    return 0;
}

