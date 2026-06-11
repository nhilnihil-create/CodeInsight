#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod=998244353;

#define pb push_back

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t,s;
    ll lim=1000000000;
    cin>>s;
    ll r=(lim-s%lim)%lim;
    ll k=(r+s)/lim;
    cout<<0<<" "<<0<<" "<<lim<<" "<<1<<" "<<r<<" "<<k;


    return 0;
}

