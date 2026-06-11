#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,ans=1;
    string s;
    cin>>n>>s;
    rep(i,n-1){
        if(s[i]!=s[i+1]){
            ans++;
        }
    }
    cout<<ans;
}