#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n, m, x;
    cin >> n >> m >> x;
    vector<long long> c(n);
    vector<vector<long long> > a(n, vector<long long>(m));

    for(long long i = 0; i < n; i++){
        cin >> c[i];
        for(long long j = 0; j < m; j++) cin >> a[i][j];
    }

    long long minv = 1e9;
    vector<bool> buy(n); 
    for(long long bit = 0; bit < (1 << n); bit++){
        for(long long mask = 0; mask < n; mask++){
            if(bit & (1 << mask)) buy[mask] = true;
            else buy[mask] = false;
        }
        long long cost = 0;
        vector<long long> algo(m, 0);
        for(long long i = 0; i < n; i++){
            if(buy[i] == false) continue;
            cost += c[i];
            for(long long j = 0; j < m; j++) algo[j] += a[i][j];
        }

        bool flag = true;
        for(long long i = 0; i < m; i++){
            if(algo[i] < x){
                flag = false;
                break;
            }
        }
        if(flag == true) minv = min(minv, cost);
    }

    if(minv == 1e9) printf("-1\n");
    else printf("%lld\n", minv);

    return 0;
}