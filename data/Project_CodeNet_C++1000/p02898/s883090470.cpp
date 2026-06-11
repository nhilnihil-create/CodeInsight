
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i,n) cin >> h[i];

    int ans=0;
    rep(i,n){
        if(h[i] >= k) ans ++;
    }

    cout << ans << endl;

}