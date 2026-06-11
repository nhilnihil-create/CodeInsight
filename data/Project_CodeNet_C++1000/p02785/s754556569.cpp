#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n, k; cin >> n >> k;
    vector<int> h(n);
    for(int i=0; i<n; ++i){cin >> h[i];}
    sort(h.begin(), h.end(), greater<int>());
    ll cnt = 0;
    for(int i=k; i<n; ++i){
        cnt += h[i];
    }
    cout << cnt << endl;
    return 0;
}