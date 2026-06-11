#include <bits/stdc++.h>
#define rep( i, n ) for (ll i = 0; i < ( ll )(n); i++)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > P;
typedef tuple<int, int, int> T;



int main(){
    ll a,b,n;
    ll ans;
    cin>>n>>a>>b;

    if(a>=n) ans=n;
    else ans=n/(a+b)*a+min(a,n%(a+b));
    cout<<ans;
}