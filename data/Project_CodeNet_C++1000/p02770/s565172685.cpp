#include <bits/stdc++.h>
using namespace std;

int main(){
    int k, q;
    cin >> k >> q;

    vector<long long int> d(k);
    for(int i=0; i<k; i++){
        cin >> d[i];
    }

    for(int i=0; i<q; i++){
        int n, x, m;
        cin >> n >> x >> m;

        long long int xn = x, ans = n-1;
        for(int i=0; i<k; i++){
            xn += (((n-1)-i) + k - 1) / k * (d[i] % m);
            if(d[i] % m == 0){
                ans -= (((n-1)-i) + k - 1) / k;
            }
        }
        cout << ans - (xn / m - x / m) << endl;
    }
    return 0;
}