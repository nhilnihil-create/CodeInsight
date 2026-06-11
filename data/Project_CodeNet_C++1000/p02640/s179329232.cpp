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

ll solve(ll a,ll b)
{
    return a*2+b*4;
}

int main(){
    optimize();
    ll T=1;
    //cin>>T;
    while(T--)
    {
        ll x,n;
        cin>>x>>n;
        for(int i=0; i<=x/2; i++)
        {
            ll a=solve(i,x-i);
            ll b=solve(x-i,i);
            if(a==n || b==n)
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
        cout<<"No"<<endl;
    }
    return 0;
}
