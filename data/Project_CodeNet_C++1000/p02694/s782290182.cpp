#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define deb(x) cout<< #x << " " << x << "\n";
#define INF 9223372036854775807
const ll mod=998244353;


int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll x;
    cin>>x;
    ll n=100;
    ll ans=0;
    while(n<x){
        n+=(n/100);
        ans++;
    }
    cout<<ans;
    
    return 0;
}