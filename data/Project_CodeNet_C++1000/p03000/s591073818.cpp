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

        int n,x;
        cin>>n>>x;
        int ans=1;
        int d=0;
        for(int i=0;i<n;i++)
        {
           int y;
           cin>>y;
           d=y+d;
           if(d<=x)
            ans++;

        }
        cout<<ans<<endl;
    }