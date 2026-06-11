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
    
    vector<int64_t> a(n);
    //map<int,ll> m;
    rep(i,n)cin>>a[i], a[i]--;
    
    vector<int64_t> m(n,0);
    rep(i,n)m[a[i]]++;
    
    int64_t ans = 0;
    /*
    for(auto p: m){
        ans += p.second*(p.second-1)/2;
    }
    */
    
    rep(i,n)ans += m[i]*(m[i]-1)/2;
    
    for(int i=0; i<n; i++){
        cout << ans -( m[a[i]] - 1 ) << endl;
    }
    
    return 0;
}