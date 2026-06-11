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

        double w,h,x,y;
        cin>>w>>h>>x>>y;
        cout<<fixed<<setprecision(12);
       cout<<(w*h)/2<<' ';
       if(x==(w/2)&&y==(h/2))
        cout<<1<<endl;
    else
        cout<<0<<endl;
    }