#include<bits/stdc++.h>
using namespace std;
int main(){
    long long k, q;
    cin >> k >> q;
    vector<long long>d(k + 3);
    for(long long i = 0; i < k; i++){
        cin >> d[i];
    }
    for(long long i = 0; i < q; i++){
        long long n, m, x;
        cin >> n >> x >> m;
        x = x % m;
        vector<long long>d2(k + 3);
        for(long long j = 0; j < k; j++){
            d2[j] = d[j] % m;
        }
        long long cnt = n - 1, val = x;
        for(long long j = 0; j < k; j++){
            long long z = (n + k - 2 - j)/k;
            if(z < 0){
                z = 0;
            }
            if(d2[j] == 0){
                cnt -= z;
            }
            val += z * d2[j];
        }
        cnt -= val/m;
        cout << cnt << '\n';
    }
    return 0;
}