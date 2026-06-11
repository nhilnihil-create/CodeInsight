#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(ll i=0;i<(ll)n;i++)

int main(){
    ll a,b,c; cin >> a >> b >> c;
    ll d = (c-a-b);
    bool e = (4*a*b < d*d);

    if(e && d>0) cout << "Yes" << endl;
    else cout << "No" << endl;
}