#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

int len(ll x){
    int l = 0;
    while(x){
        ++l;
        x /= 10;
    }
    return l;
}

int sum(ll x){
    int s = 0;
    while(x){
        s += x%10;
        x /= 10;
    }
    return s;
}

ll ext(ll x){
    ll ans = 0;
    ll div = 10;
    while(div <= x){
        ans += x/div;
        div *= 10;
    }
    return ans;
}

ll f(ll x){
    if(x <= 9) return 0;
    
    ll l = len(x), s = sum(x);
    ll ans = l-len(s) + ext(s) + f(s);
    return ans;
}

void solve(){
    int m;
    cin >> m;
    ll l = 0, s = 0;
    for(int i = 0; i < m; ++i){
        int d;
        ll c;
        cin >> d >> c;
        l += c;
        s += c*d;
    }

    ll ans = l-len(s) + ext(s) + f(s);
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}