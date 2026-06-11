#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main(){   
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    rep(i,m) n -= a[i];
    if(n < 0) n = -1;
    cout << n << endl;
    
}
