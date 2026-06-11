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
        ll a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
         ll x=a[n-1];
         int f=0;
        for(int i=n-2;i>=0;i--)
        {
            if(f&1)
                x-=a[i];
            else
                x+=a[i];

            f++;

        }
        int ans[n];
        ans[n-1]=x;
        for(int i=n-2;i>=0;i--)
        {
            ans[i]=2*(a[i]-(ans[i+1]/2));
        }
        for(int  i=0;i<n;i++)
            cout<<ans[i]<<' ';
        cout<<endl;


    }