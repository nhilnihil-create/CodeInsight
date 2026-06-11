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
#define pb push_back
#define MOD 1000000007
typedef long long ll;


int main(){
    optimize();
    ll T=1;
    //cin>>T;
    while(T--)
    {
        ll ans = 0;
        FOR(i,0,4)
        {
            int x;
            cin>>x;
            if(x==0)
            {
                ans = i+1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
