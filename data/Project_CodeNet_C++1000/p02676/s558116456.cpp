#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fi first
#define se second
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define debug(a) cout << #a << " = " << a << " ";
#define endl "\n"
#define MOD (int) 1e9+7
#define inf (int) (1e18)

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    if(s.size()<=n){
        cout<<s<<endl;
    } else {
        cout<<s.substr(0,n)<<"..."<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t=1;
    // cin >> t;
    for(long int tt=1;tt<=t;tt++){
        solve();
    }
    return 0;
}