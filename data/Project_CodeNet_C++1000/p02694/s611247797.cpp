#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll x,p=100,k=0;
    cin>>x;
    while(1){
        p+=p/100;
        k++;
        if(p>=x){
            break;
        }
    }
    cout << k;
}