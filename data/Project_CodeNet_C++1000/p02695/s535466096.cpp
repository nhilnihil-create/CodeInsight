#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
vector<ll> temp;
vector<vector<ll>> v;
ll n, m, q, ans = 0;
void solve(int idx, int numb){
    if(idx >= n){
        v.push_back(temp);
        return;
    }
    for(int i = numb; i <= m; i++){
        temp[idx] = i;
        solve(idx + 1, i);
    }
}
int main(){
    Hello
    cin >> n >> m >> q;
    ll a[q], b[q], c[q], d[q];
    for(int i = 0; i < q; i++)
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    temp.resize(n);
    solve(0, 1);
    for(int i = 0; i < v.size(); i++){
        ll cur = 0;
        for(int k = 0; k < q; k++)
            if(v[i][b[k] - 1] - v[i][a[k] - 1] == c[k])
                cur += d[k];
        ans = max(ans, cur);
    }
    cout << ans;
    return 0;
}