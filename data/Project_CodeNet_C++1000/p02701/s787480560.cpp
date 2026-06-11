#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,k;
    cin>>n;
    vector<string> s(n);
    rep(i,n){
        cin>>s[i];
    }
    sort(s.begin(),s.end());
    k=n;
    rep(i,n-1){
        if(s[i]==s[i+1]){
            k--;
        }
    }
    cout<<k;
}