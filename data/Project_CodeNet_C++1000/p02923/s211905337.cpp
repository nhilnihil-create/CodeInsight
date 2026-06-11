#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    long n;
    cin >> n;

    vector<long> h(n);
    for (long i=0; i<n; i++) {
        cin >> h.at(i);
    }

    long cnt=0;
    long maxcnt=0;
    for (long i=1; i<n; i++) {
        if (h.at(i)<=h.at(i-1)) {
            cnt++;
            maxcnt=max(maxcnt, cnt);
        } else {
            cnt=0;
        }
    }

    cout << maxcnt << endl;
    return 0;
}
