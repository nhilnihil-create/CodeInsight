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

        string s;
        cin>>s;
        string ans="Good";
        for(int i=0;i<3;i++)
        {
            if(s[i]==s[i+1])
                ans="Bad";
        }

        cout<<ans<<endl;


    }