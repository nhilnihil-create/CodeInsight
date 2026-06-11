#include <bits/stdc++.h>
#define ll long long
#define ar array
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;

ll n, ans;

int main(){
    AC
    cin>>n;
    ll ans = 0;
    for(int i=1; i<=n; i++){
        int k = n/i;
        ans+=(ll)(i+k*i)*k/2;
    }
    cout<<ans<<endl;
}