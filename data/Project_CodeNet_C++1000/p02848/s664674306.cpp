#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 2e5 + 2, inf = 1e18;

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    char ch;
    while (cin >> ch) {
        cout << (char)((ch - 'A' + n) % 26 + 'A');
    }    
}
