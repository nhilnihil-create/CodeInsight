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
    int n,m,ok=0,s=0;
    cin>>n>>m;
    vi vs(n);
    for(int &x:vs){
        cin>>x;
        s+=x;
    }
    for(int x:vs){
        if(4*m*x >= s)
            ok++;
    }
    cout << (ok>=m ? "Yes" : "No") << endl;
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