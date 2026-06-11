#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n, -1);
    rep(i,k){
        int d; cin >> d;
        rep(j,d){
            int A;
            cin >> A;
            a[A-1] = 1; 
        }
    }
    int ans = 0;
    rep(i,n){
        // cout << a[i] << endl;
        if(a[i] != 1) ans++;
    }
    cout << ans << endl;
    return 0;
}