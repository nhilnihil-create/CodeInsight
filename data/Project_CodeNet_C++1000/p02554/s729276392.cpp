typedef long long ll;
#include<bits/stdc++.h>
using namespace std;
ll maxl(ll a, ll b){ return ((a<b)?b:a);}
ll minl(ll a, ll b){ return ((a>b)?b:a);}

ll expo(int x, int n){
    if (n == 0)
        return 1;
    ll val = expo(x,n/2);
    int M = 1e9 + 7;
    val = (val*val)%M;
    if (n%2!=0)
        val = (val*x)%M;
    return val;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int M = 1e9 + 7;
    ll val1 = expo(10,n);
    ll val2 = expo(9,n);
    ll val3 = expo(8,n);
    val1 = (val1+val3)%M;
    val2 = (val2*2)%M;
    ll ans = (val1 - val2 + M)%M;
    cout << ans << "\n";
}

