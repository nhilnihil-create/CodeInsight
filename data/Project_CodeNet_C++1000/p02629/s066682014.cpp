#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i=0; i < (ll)(n); i++)

int main(void){
    ll n;
    cin>>n;
    ll a;
    string ans;
    while(n>0){
        a=n%26+96;
        n/=26;
        if(a==96){
            a+=26;
            n-=1;
        }
        ans = char (a) + ans;
    }
    cout<<ans<<endl;
}