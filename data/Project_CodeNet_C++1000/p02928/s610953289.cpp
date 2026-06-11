#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long mod = 1e9 + 7;

int main(){
    long long n ,k;
    cin >> n >> k;

    vector<long long> a(n);
    for(long long i = 0; i < n; i++) cin >> a[i];

    vector<long long> a2(2*n);
    for(long long i = 0; i < n; i++){
        a2[i] = a[i];
        a2[i+n] = a[i];
    }

    long long cnt_in = 0;
    for(long long i = 0; i < n; i++){
        for(long long j = i + 1; j < n; j++){
            if(a[i] > a[j]) cnt_in++;
        }
    }
    //printf("cnt_in %lld\n", cnt_in);

    long long cnt_2 = 0;
    for(long long i = 0; i < 2*n; i++){
        for(long long j = i + 1; j < 2*n; j++){
            if(a2[i] > a2[j]) cnt_2++;
        }
    }

    cnt_in %= mod;

    long long cnt_out = cnt_2 - 2 * cnt_in;
    //cnt_out += mod;
    cnt_out %= mod;

    //printf("cnt_out %lld\n", cnt_out);

    long long ans = (cnt_in * k)%mod + cnt_out * (k * (k-1)/2%mod);
    ans %= mod;

    cout << ans << endl;

    return 0;
}