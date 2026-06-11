#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll k,a=7,ans=1,t,p[1000001];
    rep(i,1000001){
        p[i]=0;
    }
    cin>>k;
    while(1){
        t=a%k;
        if(t==0){
            break;
        }
        if(p[t]==1){
            cout<<-1;
            return 0;
        }
        a=t*10+7;
        ans++;
        p[t]=1;
    }
    cout<<ans;
}