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
    for(long long x = 0; x < n; x++){
        for(long long y = x + 1; y < n; y++){
            long long dist = lower_bound(l.begin(), l.end(), l[x]+l[y]) - l.begin();
            cnt += dist - (y+1);
        }
    }
    cout << cnt << endl;
    return 0;
}