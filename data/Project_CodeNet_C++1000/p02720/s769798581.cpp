#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()
 
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
 
const int oo = 1e9 + 7;
const int mod = 1e9 + 7, maxn = 2010;
const long double PI = acos(-1);

bool f(ll n){
    ll l = n%10;
    while(n){
        if (abs(n%10 - l) > 1) return false;
        n/=10;
    }
    return true;
}

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<ll> ans, a;

    for (int i=1; i<10; i++) a.push_back(i), ans.push_back(i);

    while(ans.size() < 100000){
        vector<ll> next;
        for (int i=0; i<10; i++){
            for (auto x: a){
                if (abs(x%10 - i) <= 1) {
                    next.push_back(x*10+i);
                    ans.push_back(x*10+i);
                }
            }
        }
        a = next;
    }

    sort(all(ans));
    cout << ans[n-1] << endl;
    return 0;
}