#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using vec = vector<ll>;
using vec2 = vector<vector<ll>>;
ll inf = pow(2, 62);

int main(){
    ll n;cin >> n;
    vec A(n);
    rep(i,n){
        cin >> A[i];
    }
    sort(A.begin(),A.end());
    reverse(A.begin(),A.end());
    ll ans = A[0];
    for(int i = 1;i < n-1;i++){
        if(i%2 == 1){
            ans += A[(i+1)/2];
        }
        if(i%2 == 0){
            ans += A[i/2];
        }
    }
    cout << ans << endl;
}