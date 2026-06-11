#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long> l(n);

    for(long long i = 0; i < n; i++) cin >> l[i];

    sort(l.begin(), l.end());

    long long cnt = 0;

    for(long long i = 0; i < n; i++){
        for(long long j = i + 1; j < n ; j++){
            long long k = lower_bound(l.begin(), l.end(), l[i]+l[j]) - l.begin();
            cnt += k - (j+1);
        }
    }
    cout << cnt << endl;
    return 0;
}