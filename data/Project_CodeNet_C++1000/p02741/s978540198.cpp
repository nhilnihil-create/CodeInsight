#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, mod = 1e9 + 7;



int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int tc = 1; 
    //scanf("%d", &tc);
    vector<int> v = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    while(tc--) {
        int k; cin >> k;
        cout << v[k - 1] << '\n';
    }    
    return 0;
}