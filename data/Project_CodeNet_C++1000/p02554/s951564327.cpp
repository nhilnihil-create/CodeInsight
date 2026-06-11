#include <vector>
#include <iostream>
using namespace std;
#define ll long long
ll mod = 1000000007;
int main(){
    int n; cin >> n;
    ll a = 1;
    ll b = 2; 
    ll c = 1;
    for(int i=1;i<=n;i++){
        a*=10;
        a%=mod;
    }
    for(int i=1;i<=n;i++){
        b*=9;
        b%=mod;
    }
    for(int i=1;i<=n;i++){
        c*=8;
        c%=mod;
    }
    ll ans = a-b+c;
    ans%=mod;
    if(ans<0) ans+=mod;
    cout << ans;
}

