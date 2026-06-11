#include <bits/stdc++.h>
#define rep(i, n) = for(int i=0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    int max = -1;
    int ans = 0;
    for(int i=0; i < n; ++i){
        cin >> a[i];
    }
    vector<int> dist(n+1);
    for(int i=0; i < n; ++i){
        if(i == 0) dist[i] = k + a[0] - a[n-1];
        else dist[i] = a[i] - a[i-1];
        ans += dist[i];
        if(max < dist[i]) max = dist[i];
        // cout << dist[i] << " ";
    }
    // cout << endl;
    ans -= max;
    cout << ans << endl;
    return 0;
}