#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n, m, v, p;
vector <int> a;

bool check(int idx){
    int tar = a[idx] + m;
    if(tar < a.back()) return 0;
    ll sum = 0;
    for(int i = idx + 1 ; i < n ; i++){
        sum += tar - a[i];
    }
    if(sum - 1LL * m * (v - (idx + 1)) < 0) return 0;
    return 1;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> v >> p;
    a.resize(n);
    for(auto &i : a) cin >> i;
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0 ; i < p - 1 ; i++){
        ans++;
        v--;
        a.pop_back();
    }
    n = a.size();
    int l = 0, r = n - 1;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    ans += n - l;
    cout << ans << endl;
}
