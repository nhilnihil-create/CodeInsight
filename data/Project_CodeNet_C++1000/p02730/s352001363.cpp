#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vll vector<ll>
#define vii vector<ii>

const int maxn = 1e5+10;
const int mod = 1e9+7;

using namespace std;

void solve(){
    string s;
    bool ok = true;
    cin>>s;
    int n =(int)s.size();
    for(int i=0;i<n/2;++i){
        if(s[i]!=s[n-i-1])
            ok=false;
    }
    for(int i=0;i<(n-1)/2;++i){
        if(s[i]!=s[(n-1)/2-i-1])
            ok=false;
    }
    for(int i=(n+3)/2;i<n;++i){
        if(s[i]!=s[n-i-1])
            ok=false;
    }
    if(ok)
        cout<<"Yes\n";
    else
        cout<<"No\n";
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}