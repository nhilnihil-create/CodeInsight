#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll n,x;
    cin>>n;
    rep(i,n){
        cin>>x;
        if(x%2==0){
            if(x%3!=0&&x%5!=0){
                cout<<"DENIED";
              return 0;
            }
        }
    }
    cout<<"APPROVED";
}