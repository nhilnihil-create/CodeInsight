#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void) {
    int k, q;
    cin >> k >> q;
    vector<int> d(k);
    for(int i=0; i<k; i++) {
        cin >> d[i];
    }

    while(q--) {
        int n, x, m;
        cin >> n >> x >> m;
        x %= m;
        vector<int> tmp(k);
        transform(d.begin(), d.end(), tmp.begin(), [m](int d) {return d % m;});
        int64_t sum = accumulate(tmp.begin(), tmp.end(), 0L);
        int64_t zero = count(tmp.begin(), tmp.end(), 0);
        sum *= (n-1) / k;
        zero *= (n-1) / k;
        for(int i=0; i<(n-1)%k; i++) {
            sum += tmp[i];
            if(tmp[i] == 0) zero++;
        }
        sum += x;
        cout << n-1 - zero - (sum / m) << endl;
    }
    return 0;
}
