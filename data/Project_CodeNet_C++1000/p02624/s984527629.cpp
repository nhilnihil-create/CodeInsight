#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<long long> num_divisors_table(long long n){
    vector<long long> table(n+1, 0);

    for(long long i = 1; i <= n; i++){
        for(long long j = i; j <= n; j = j+ i){
            table[j] += 1;
        }
    }
    return table;
}

int main(){
    long long n;
    cin >> n;

    vector<long long> table;
    table = num_divisors_table(n);
    long long ans = 0;

    for(long long i = 1; i <= n; i++){
        ans += i * table[i];
    }

    cout << ans << endl;
    return 0;
}