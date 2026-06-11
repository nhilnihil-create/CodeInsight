#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;
const int INF = 1000100100;


int main(){
    ll n,k,a[200005],cnt=0,ans;
    string s;
    cin>>n;
    cin>>s;
    rep(i,n){
        if(s[i]=='W'){
            cnt++;
            if(i>0){
                a[i]=a[i-1]+1;
            }else{
                a[0]=1;
            }
        }else{
            if(i>0){
                a[i]=a[i-1];
            }else{
                a[0]=0;
            }
        }
    }
    if(cnt==n){
        ans=0;
    }else{
        ans=a[n-cnt-1];
    }
    cout<<ans;
}