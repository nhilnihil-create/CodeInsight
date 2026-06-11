#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;

int main(){
    ll a,b,ans=-1;
    cin>>a>>b;
    for(int i=b*10;i<(b+1)*10;i++){
        if((ll)(i*0.08+0.001)==a){
            ans=i;
            break;
        }
    }
    cout <<ans;
}