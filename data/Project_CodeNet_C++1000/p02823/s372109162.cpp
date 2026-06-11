#include <iostream>
typedef long long ll;
using namespace std;

ll N, A, B;

ll solve() {
    ll diff = B-A, temp = diff/2, dist;
    if(diff%2 == 0) { // even
        ll avg = (A+B)/2;
        dist = B-avg;
    }
    else {  // odd
        // If A is nearer to leftmost table than rightmost,
        if((B-1) <= (N-A)) dist = B-1-temp;
        else dist = N-A-temp;
    }
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> A >> B;

    cout << solve() << endl;
    exit(0);
}