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
        string s[]={"SUN", "MON", "TUE", "WED", "THU", "FRI","SAT"};
        string t;
        cin>>t;
        for(int i=0;i<7;i++)
        {
            if(t==s[i])
            {
                cout<<7-i<<endl;
                break;
            }
        }

    }