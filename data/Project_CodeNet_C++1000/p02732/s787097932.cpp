#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb(a) push_back(a)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
using P  = pair<int,int>;
using vP = vector<P>;
const int INF = 1001001001;

int main(){
    int n;
    cin>>n;
    
    vi a(n);
    map<int,ll> m;
    
    rep(i,n){
        cin>>a[i];
        m[a[i]]++;
    }
    
    ll ans = 0;
    
    for(auto p: m){
        ans += p.second*(p.second-1)/2;
    }
    
    for(int i=0; i<n; i++){
        cout << ans -( m[a[i]] - 1 ) << endl;
    }
    
    return 0;
}