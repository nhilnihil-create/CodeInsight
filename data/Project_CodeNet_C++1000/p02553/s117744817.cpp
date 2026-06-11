#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define ld  long double
#define endl '\n'
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll MOD = (ll)1e9+7;
const double PI = 3.141592653589793238463;
const int MAXN = 1000030;
int main() {
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<max({a*c,a*d,b*c,b*d})<<endl;
    return 0;
}