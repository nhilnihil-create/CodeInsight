#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,k;
    cin >>n>>k;
    if(n>=k){
        n-=(n/k)*k;
    }
    if(n>abs(k-n)){
            n=abs(k-n);
        }
    cout << n;
}