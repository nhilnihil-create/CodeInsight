#include <bits/stdc++.h>
using namespace std;
int main(){
        long long int a, b, k; cin >> a >> b >> k;
        long long int z = 0;
        if (k <= a) cout << a-k << " " << b << endl;
        else cout << 0 << " " << max(z, b-(k-a)) << endl;
    return 0;
}

