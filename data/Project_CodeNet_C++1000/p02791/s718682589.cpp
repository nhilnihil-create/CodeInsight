#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define rrep(i,n) for(int i=1; i<n; i++)
using namespace std;
using vi = vector<int>;

int main(){
    int n, k, m, c=0;
    cin >> n;
    vi ps(n);
    vi pmin(n);
    cin >> ps.at(0);
    m = ps.at(0);
    pmin.at(0) = m;
    rrep(i,n){
        cin >> k;
        ps.at(i) = k;
        m = min(m, k);
        pmin.at(i) = m;
    }
    rep(i,n){
        if (ps.at(i) == pmin.at(i))c += 1;
    }
    cout << c << '\n';
}