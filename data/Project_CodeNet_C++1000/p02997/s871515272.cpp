#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;

    int mx=(n-1)*(n-2)/2;
    if ( k>mx ) {
        puts("-1");
        return 0;
    }
    vector<pair<int,int>> e;
    // star
    for ( int i=2; i<=n; i++ ) {
        e.emplace_back(1,i);
    }

    int total=mx;
    for ( int i=2; i<=n; i++ ) {
        for ( int j=i+1; j<=n; j++ ) {
            if ( total>k ) {
                e.emplace_back(i,j);
                total--;
            } 
        }
    }
    cout << e.size() << '\n';
    for ( int i=0; i<e.size(); i++ ) {
        cout << e[i].first << ' ' << e[i].second << '\n';
    }
    return 0;
}