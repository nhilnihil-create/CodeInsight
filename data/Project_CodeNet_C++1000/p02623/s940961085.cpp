#include<iostream>
using namespace std;
const int BUF = 200005;


int nA, nB, limit;
int aVal[BUF], bVal[BUF];

void read() {
    cin >> nA >> nB >> limit;
    for (int i = 0; i < nA; ++i) cin >> aVal[i];
    for (int i = 0; i < nB; ++i) cin >> bVal[i];
}


void work() {
    int ans = 0;
    
    long long sum = 0;
    int bIdx = 0;
    while (bIdx < nB && sum + bVal[bIdx] <= limit) {
        sum += bVal[bIdx++];
    }

    ans = bIdx;

    for (int aIdx = 0; aIdx < nA; ++aIdx) {
        sum += aVal[aIdx];
        while (bIdx - 1 >= 0 && sum > limit) {
            --bIdx;
            sum -= bVal[bIdx];
        }
        
        if (sum <= limit) {
            ans = max(ans, aIdx + 1 + bIdx);
        }
    }

    cout << ans << endl;
}


int main() {
    read();
    work();
    return 0;
}
