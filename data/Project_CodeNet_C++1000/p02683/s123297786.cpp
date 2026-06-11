#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n, m, x;
    cin >> n >> m >> x;

    vector<vector<long long> > a(n, vector<long long>(m));
    vector<long long> c(n);
    for(long long i = 0; i < n; i++){
        cin >> c[i];

        for(long long j = 0; j < m; j++) cin >> a[i][j];
    }

    long long minv = 1e9;
    bool buy = false;
    for(long long bit = 0; bit < (1 << n); bit++){
        vector<long long> skill(m, 0);
        long long cost = 0;
        for(long long mask = 0; mask < n; mask++){
            if(bit & (1 << mask)){
                cost += c[mask];

                for(long long i = 0; i < m; i++){
                    skill[i] += a[mask][i];
                }
            }
        }

        bool flag = true;
        for(long long i = 0; i < m; i++){
            if(skill[i] < x){
                flag = false;
                break;
            }
        }

        if(flag == true) minv = min(minv, cost), buy = true;

    }

    if(buy != true) printf("-1\n");
    else cout << minv << endl;
    return 0;
}