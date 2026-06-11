#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,k,sum=0;
  	cin >>n >>k;
    for(int i=k;i<=n+1;i++){
        sum+=(i%mod)*(n-i+1)+1;
        sum=sum%mod;
    }
    cout << sum;
}