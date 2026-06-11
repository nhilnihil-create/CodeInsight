#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<ll, int>;



int main(){
    int n; cin >> n;
    ll ans = 0;
    vector<int> c(n+1);
    for(int k = 1; k <= n; k++){
        for(int i = k; i <= n; i += k){
            c[i]++;
        }
    }
    for(int i = 1; i <= n; i++) ans += ll(i) * c[i];
    cout << ans << endl;
}