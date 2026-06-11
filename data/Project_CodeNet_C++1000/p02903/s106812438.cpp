#include <bits/stdc++.h>
using namespace std;
 
#define forn(i,n) for(int i=0;i<(int)(n);i++)
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,a,b; cin >> n >> m >> a >> b;
    forn(i,n) { 
        forn(j,m) {
            cout << ((j < a) ^ (i < b));
        }
        cout << '\n';
    }
    return 0;
}
