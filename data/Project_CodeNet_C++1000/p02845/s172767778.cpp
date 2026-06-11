#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main() {
    int n;
    cin>>n;
    int a[n];
    rep(i,n) cin>>a[i];
    vector<int> b(n,0);
    b[0]=3;
    ll ans=1;
    rep(i,n){
        ans=(ans*b[a[i]])%MOD;
        b[a[i]]--;
        b[a[i]+1]++;
    }
    cout<<ans<<endl;
    return 0;
}

