#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);


int main(void)
{
    ll n,a,b; cin>>n>>a>>b;
    if(abs(a-b)%2 == 0) cout << abs(a-b)/2 << endl;
    else cout << min(a-1, n-b)+1+(b-a-1)/2 << endl;
    return 0;
}