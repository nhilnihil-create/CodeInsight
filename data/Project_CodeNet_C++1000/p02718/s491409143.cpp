#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;

int main(){
    int n, m, sum = 0;
    cin >> n >> m;
    vi a(n);
    rep(i, n){
        cin >> a[i];
        sum += a[i];
    }
    double cmp = sum / (4.0*m);
    sort(a.begin(), a.end(), greater<int>());
    bool flg = true;
    rep(i, m){
        if(a[i] < cmp) flg = false;
    }

    if(flg) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}