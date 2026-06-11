//author: Harsh Nema
#include <bits/stdc++.h>
#define ll long long int
#define F first
#define S second
const ll mod = 1e9 + 7;
const ll INF = 922337203685477;
#define pb push_back
#define deb(x) cout << '>' << #x << ':' << x << endl;
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;
int main()
{
    fastio;
    ll k=0,x=0;
    cin>>k>>x;
    for(ll i=x-k+1;i<=x+k-1;++i)
        cout<<i<<" ";
    return 0;
}
