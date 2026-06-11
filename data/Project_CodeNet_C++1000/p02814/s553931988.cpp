#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

ll gcd(ll a, ll b) {return b?gcd(b, a%b):a;}
ll lcm(ll a, ll b) {return a/gcd(a, b)*b;}

int f(int x){
    int t = 0;
    while(x%2 ==0){
        t++;
        x /= 2;
    }
    return t;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n){
        if(a[i]%2 == 1){
            cout << 0 << endl;
            break;
        }
        a[i] /= 2;
    }
    int t = f(a[0]);
    rep(i, n){
        if(f(a[i]) != t){
            cout << 0 << endl;
            return 0;
        }
        a[i] >>= t;
    }
    m >>= t;
    int l = 1;
    rep(i, n){
        l = lcm(l, a[i]);
        if(l > m){
            cout << 0 << endl;
            return 0;
        }
    }
    int ans = (m /l + 1)/2;
    cout << ans << endl;
}