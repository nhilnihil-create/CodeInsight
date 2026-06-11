#include <bits/stdc++.h>
using namespace std;
int main(){
        long long int n, m; cin >> n >> m;
        long long int a = 0;
        for (long long int x = 0; x < m; ++x){
            long long int q; cin >> q;
            a += q;
        }
        cout << ((n - a) >= 0 ? n-a : -1) << endl;
    return 0;
}

