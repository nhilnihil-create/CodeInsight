#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n - 1);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n - 1) cin >> c[i];
    int en = 0, add = 0;
    rep(i, n){
        en += b[a[i] - 1];
        if(add != 0 && a[i - 1] + 1 == a[i]){
            en += add;
        }
        if(a[i] - 1 != n - 1){
            add = c[a[i] - 1];
        }
    }
    cout <<  en << endl;;
    return 0;
}