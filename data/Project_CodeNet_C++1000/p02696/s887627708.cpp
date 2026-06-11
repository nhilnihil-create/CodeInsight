#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n) ; i++)
#define rrep(i,n) for(int i = n-1; i >= 0 ; i--)
typedef long long ll;
constexpr auto INFI = 2147483647;
const ll INFL = 9223372036854775807;

ll func(ll a,ll b,ll x){
    return ((a * x) - (a * x % b)) / b;
};

int main(){
    ll a, b, n;
    cin >> a >> b >> n;
    ll x = min(n, b-1);

    cout << func(a, b, x) << endl;

    return 0;
}