   #include<bits/stdc++.h>
    using namespace std;

    #define ll long long
    #define ff first
    #define ss second
    #define pb push_back
    #define vll vector<ll>
    #define mll map<ll,ll>
    #define MOD 1000000007
    #define pll pair<ll,ll>
constexpr ll INF = 1999999999999999997; 
    #define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
    int main() {
        fastio;

        int n;
        cin>>n;
        vector<pll> v;
        for(int i=0;i<n;i++)
        {
            ll a,b;
            cin>>a>>b;
            v.pb({b,a});
        }
        sort(v.begin(),v.end());
        ll t=0;
        string ans="Yes";
        for(auto j : v)
        {   
               t+=j.ss;
               if(t>j.ff)
                ans="No";
        }
        cout<<ans<<endl;
    }