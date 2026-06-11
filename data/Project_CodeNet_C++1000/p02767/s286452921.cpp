#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    cin >> n;
    int x[n];
    int max_x=0;
    rep(i, n){
        cin >> x[i];
        max_x=max(max_x, x[i]);
    }

    ll ans=1e9;
    rep(i, max_x){
        ll sum=0;
        rep(j, n){
            sum+=pow(x[j]-(i+1), 2);
        }
        ans=min(ans, sum);
    }
    cout<<ans<<endl;
    return 0;
}