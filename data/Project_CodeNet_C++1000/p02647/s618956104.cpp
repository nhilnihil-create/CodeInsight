#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<long long> solve(vector<long long> light){
    long long n = light.size();
    vector<long long> table(n, 0);
    for(long long i = 0; i < n; i++){
        long long start = max(0ll, i - light[i]);
        long long goal = min(n-1, i + light[i]);
        table[start]++;
        if(goal+1 < n) table[goal+1]--;
    }

    for(long long i = 0; i < n; i++){
        if(i > 0) table[i] += table[i-1];
    }
    return table;
}
int main(){
    long long n, k;
    cin >> n >> k;
    vector<long long> light(n);

    vector<long long> light_max(n, n);

    for(long long i = 0; i < n; i++){
        cin >> light[i];
    }

    for(long long i = 0; i < k; i++){
        light = solve(light);
        if(light == light_max){
            for(long long j = 0; j < n; j++){
                printf("%lld ", light_max[j]);
            }
            printf("\n");
            return 0;
        }
    }

    for(long long i = 0; i < n; i++){
        printf("%lld ", light[i]);
    }
    printf("\n");
    return 0;
}