#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "

int main(){
    ll ans = 0;
    int n;cin>>n;
    vector<ll>a(n);rep(i, n)cin>>a[i];
    sort(a.begin(), a.end(), greater<int>());
    rep(i, n-1){
        ans += a[(i+1)/2];
    }
    co(ans);
}