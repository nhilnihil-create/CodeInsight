#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < n; i++)
static const long long INF = 1000000;
using p = pair<int64_t,int64_t>;

int main(){
    int k,n;
    cin >> k >> n;
    vector<int> vec(n);
    rep(i,n){
        int a;
        cin >> a;
        vec[i] = a;
    }
    int x = 0;
    rep(i,n-1){
        x = max(x,vec[i+1] - vec[i]);

    }
    x = max(x,k-vec[n-1]+vec[0]);
    int ans = k-x;
    cout << ans << endl;
}