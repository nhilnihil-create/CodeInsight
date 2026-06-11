#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lld long double
#define w(x) ll x;cin>>x;while(x--)
#define mod 1000000007
#define speed ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

int main(){
    speed;
    ll n;   cin>>n;
    ll cnt=0;
    for(ll i=1;i<n;i++){
        for(ll j=1;j<n;j++){
            if(i*j>=n)  break;
            else{
                cnt++;
            }
        }
    }
    cout<<cnt<<'\n';
    return 0;
}