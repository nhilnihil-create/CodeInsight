#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,k=0;
    string s;
    cin >>s;
    n=s.size();
    rep(i,n/2){
        if(s[i]!=s[n-1-i]){
            k=1;
        }
    }
    rep(i,n/4){
        if(s[i]!=s[n/2-1-i]){
            k=1;
        }
        if(s[n/2+1+i]!=s[n-1-i]){
            k=1;
        }
    }
    if(k==1){
        cout <<"No";
    }else{
        cout << "Yes";
    }
}