#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;

const int MOD = 1e9+7;
const ll INF = 1e16;

int cnt(int x) {
    int total = 0;
    for(int i=1; i*i<=x; i++) {
        if(x%i == 0) {
            if(x/i == i)
                total++;
            else
                total += 2;
        }
    }
    return total;
}

int main() {
    FASTIO
    
    int n;
    cin >> n;
    
    int tuples = 0;
    for(int i=1; i<=n-1; i++) {
        tuples += cnt(n-i);
    }
    
    cout << tuples << "\n";
    
    return 0;
}