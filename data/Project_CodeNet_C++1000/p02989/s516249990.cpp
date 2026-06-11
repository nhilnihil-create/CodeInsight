#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
using ll = long long;
using namespace std;

int main(){
    int n;
    cin >> n;
    int d[n];
    rep(i, n) cin >> d[i];
    sort(d, d+n);

    int res =0;
    res = d[n/2] - d[n/2-1];
    
    cout << res << endl;
    return 0;
}