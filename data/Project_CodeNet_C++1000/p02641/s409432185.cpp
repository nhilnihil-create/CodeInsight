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
        ll x,n;
        cin>>x>>n;
        unordered_set<ll> st;
        FOR(i,0,n-1)
        {
            ll xx;
            cin>>xx;
            st.insert(xx);
        }
        if(st.find(x) == st.end())
        {
            cout<<x<<endl;
            return 0;
        }
        ll i=1;
        ll j=1;
        while(1)
        {
            ll b=x-i;
            ll a=x+j;
            if(st.find(a)!=st.end() && st.find(b)!=st.end())
            {
                i++;
                j++;
            }
            else if(st.find(b)==st.end())
            {
                cout<<b<<endl;
                return 0;
            }
            else if(st.find(a)==st.end())
            {
                cout<<a<<endl;
                return 0;
            }
        }
    }
    return 0;
}
