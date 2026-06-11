#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;
using Graph = vector<vector<pair<int, int>>>;

const ll INF = 1001001001;

int main(){
    int n, k; cin >> n >> k;
    vector<int> a(n); 
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i = 0; i < k; i++){
        ans += a[i];
    }
    cout << ans << endl;
}
