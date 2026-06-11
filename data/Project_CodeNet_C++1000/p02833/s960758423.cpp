#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,k,cnt=1,sum=0;
    cin>>n;
    if(n%2==1){
        cout<<0;
        return 0;
    }
    n/=10;
    while(n>0){
        k=n%5;
        sum+=k*cnt;
        cnt=cnt*5+1;
        n/=5;
    }
    cout<<sum;
}