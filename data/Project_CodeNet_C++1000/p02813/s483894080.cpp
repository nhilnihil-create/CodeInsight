#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

ll order(v1 a, vl cai, int n){
    ll ans = 0;
    v1 check(n+1, 0);
    for(int i = 1;i <= n; i++){
        check[i] = i;
    }
    for(int i = 1; i <= n; i++){
        int c = 0;
        for(int j = 1; j < a[i]; j++){
            if(check[j] != 0) c++;
        }
        ans += c*cai[(n-i)];
        check[a[i]] = 0;
    }
    return ans+1;
}



int main(){
    int n;
    cin >> n;
    v1 a(n+1);
    v1 b(n+1);
    for(int i = 1; i<= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> b[i];
    }
    vl cai(n+1);
    cai[0] = 1;
    for(int i = 1; i<= n; i++){
        cai[i] = cai[i-1]*i;
    }
    ll ans = abs(order(a, cai, n) - order(b, cai, n));
    cout << ans << endl;

}