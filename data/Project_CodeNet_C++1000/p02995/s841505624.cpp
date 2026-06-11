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

        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll ans=0;
        ll lc = (c*d)/(__gcd(c,d));
            ans= b/d + b/c - (a-1)/c - (a-1)/d - (b/lc - (a-1)/lc);
            cout<<(b-a+1)-ans<<endl;  
        
    }