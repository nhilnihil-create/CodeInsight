#include <bits/stdc++.h> 
using namespace std;
using ll = long long;
template<typename T> using v2 = vector<vector<T>>;
template<typename T> inline v2<T> fill(int r, int c, const T& t){ return v2<T>(r, vector<T>(c, t)); }
#define F first
#define S second

vector<ll> factor(ll x){
    vector<ll> ans;
    for(ll i = 2; i*i <= x; ++i){
        if(x%i==0){
            ans.push_back(i);
            if(i!=x/i) ans.push_back(x/i);
        } 
    }
    ans.push_back(x);
    return ans;
}

void solve(){
    ll n;
    cin >> n;
    if(n==2){
        cout << "1\n";
    }
    else{
        vector<ll> f1 = factor(n);
        vector<ll> f2 = factor(n-1);

        int ans = 0;
        for(ll i : f1){
            ll t = n;
            while(t%i==0){
                t/=i;
            }
            if(t%i==1) ++ans;
        }
        ans += (int)f2.size();
        cout << ans << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}