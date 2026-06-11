#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll k,sum=0;
    cin>>k;
    rep(i,k){
        rep(j,k){
            rep(l,k){
                sum+=__gcd(i+1,__gcd(j+1,l+1));
            }
        }
    }
    cout << sum;
}