#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for(ll i=a; i<= b; ++i)
#define all(v) (v).begin(), (v).end()
#define ff first
#define ss second
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define MOD 1000000007
typedef long long ll;


int main(){
    optimize();
    ll T=1;
    //cin>>T;
    while(T--)
    {
        ll n,d;
        cin>>n>>d;
        ll ans=0;

        FOR(i,1,n)
        {
            ll a,b;
            cin>>a>>b;
            if(a*a+b*b<=d*d) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
