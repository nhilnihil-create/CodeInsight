#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    i64 n;
    cin >> n;
    vector<i64> c(n+1);
    for(int i=0;i<n;++i){
        i64 a;
        cin >> a;
        c[a]++;
    }
    vector<i64> d(n+1);
    for(i64 i=0;i<=n;++i)d[c[i]]++;
    vector<i64> sum_d(n+2), sum_kd(n+2);
    for(i64 i=1;i<=n+1;++i){
        sum_d[i] = sum_d[i-1] + d[i];
        sum_kd[i] = sum_kd[i-1] + i*d[i];
    }
    vector<i64> f(n+1);
    for(i64 i=1;i<=n;++i){
        f[i] = (sum_kd[i] + i*(sum_d[n]-sum_d[i])) / i;
    }
    f[0] = LLONG_MAX;
    for(i64 i=1;i<=n;++i){
        i64 valid = 0, invalid = n + 1;
        while(abs(valid-invalid) > 1){
            i64 mid = (valid + invalid) / 2;
            if(f[mid] >= i)valid = mid;
            else invalid = mid;
        }
        cout << valid << endl;
    }

    return 0;
}
