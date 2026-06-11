#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)

int main() {
    int64_t n,k;
    cin >> n >> k;

    vector<int> v(n);
    rep(i, n){
        int a;
        cin >> a;
        v[i] = a;
    }

    int64_t sel = 0;
    rep(i, n){
        for(int j=i; j<n; j++){
            if(v[i] > v[j]){
                sel++;
            }
        }
    }

    int64_t rgt = 0;
    rep(i, n){
        rep(j, n){
            if(v[i] < v[j]){
                rgt++;
            }
        }
    }

    int64_t ans = 0;
    ans += sel * k;
    ans %= 1000000007;
    int64_t anstmp;
    anstmp = (k*(k-1))/2;
    anstmp %= 1000000007;
    ans += rgt * anstmp;
    ans %= 1000000007;

    cout << ans;
}