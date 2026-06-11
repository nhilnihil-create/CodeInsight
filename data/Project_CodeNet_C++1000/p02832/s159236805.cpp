#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,a,cnt=1;
    cin>>n;
    rep(i,n){
        cin>>a;
        if(a==cnt){
            cnt++;
        }
    }
    if(cnt==1){
        cout<<-1;
    }else{
        cout<<n-cnt+1;
    }
}