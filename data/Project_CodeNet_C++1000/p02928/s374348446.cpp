#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

long long r = 1e9+7;

int main(){
    long long n, k;
    cin >> n >> k;

    vector<long long> a(n);

    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }

    long long count_in = 0;
    for(long long i = 0; i < n; i++){
        for(long long j = i+1; j < n; j++){
            if(a[i] > a[j]){
                count_in++;
            }
        }
    }

    long long count_out = 0;
    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < n; j++){
            if(a[i] > a[j]){
                count_out++;
            }
        }
    }

   
    long long ans = 0;
    ans += count_in*k;
    ans = ans % r;

    long long p = (k*(k-1)/2)%r;
    ans = ans + (count_out*p)%r;
    ans %= r;
    cout << ans << endl;
   
    return 0;

}