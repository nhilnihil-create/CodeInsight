#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll a;
    cin>>a;
    string s;
    string t;
    vector<string> k(2*a);
    cin>>s>>t;
    rep(i,a){
        k[2*i]=s[i];
        k[2*i+1]=t[i];
    }
    rep(i,2*a){
      cout<<k[i];
    }
}