#include <iostream>
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#include <algorithm>
#include <bits/stdc++.h>
#define MOD 1000000000000000000
#define ll long long
#define mm(arr) memset(arr, 1, sizeof(arr))
#define scanArray(a,n) for(ll i = 0; i < n; i++){cin >> a[i];}
using namespace std;
void prime(ll n1);
int main(){
    FAST
    ll a,b; cin >> a >> b;
    ll n1 = __gcd(a,b);
    prime(n1);
    return 0;
}
void prime(ll n1){
    map<ll,ll>found;
    ll cnt=0;
    for(ll i=2; i*i<=n1; i++){
        while(n1%i == 0){
            n1/=i;
            if(found[i]>0){
                continue;
            }
            found[i]++;
            cnt++;
        }
    }
    if(n1!=1){
        cout << cnt+2 << endl;
    }
    else{
        cout << cnt+1 << endl;
    }
}
