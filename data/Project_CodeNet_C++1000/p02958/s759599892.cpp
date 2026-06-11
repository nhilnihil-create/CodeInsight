#include <bits/stdc++.h>
#define io() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); srand(time(NULL));
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

signed main(){
    io();
    int n; cin >> n;
    vector<int> a(n), b;
    int difs = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        b.push_back(i + 1);
        if(b[i] != a[i]){
            ++difs;
        }
    }
    puts(difs > 2 ? "NO\n" : "YES\n");
    return 0;
}