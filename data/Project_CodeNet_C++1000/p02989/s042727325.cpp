#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long> d(100001, 0);

    for(long long i = 0; i < n; i++){
        long long D;
        cin >> D;
        d[D]++;
    }

    vector<long long> sum(100002, 0);

    for(long long i = 0; i < 100002; i++) sum[i+1] = sum[i] + d[i];

    long long cnt = 0;

    for(long long i = 2; i <= 100002; i++){
        if(sum[i] == n/2) cnt++;
    }
    cout << cnt << endl;
    return 0;
}