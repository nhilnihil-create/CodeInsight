#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <tuple>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0; i<n; ++i)

int main() {
    int n;
    cin >> n;
    vector<long long> A(n);
    rep(i,n) cin >> A[i];

    vector<long long> dp(n); //prop
    dp.at(0) = 1000;
    for (int sellday=1; sellday<n; ++sellday) {
        dp.at(sellday) = max(dp.at(sellday), dp.at(sellday-1));
        for (int buyday=0; buyday<=sellday; ++buyday) {
            if (A[buyday] >= A[sellday])
                continue;
            long long property = dp.at(buyday);
            //buy
            long long stocks = property / A[buyday];
            long long remain = property % A[buyday];
            //sell
            property = A[sellday] * stocks + remain;
            dp.at(sellday) = max(dp.at(sellday), property);
        }
    }

    cout << dp.back() << endl;
    return 0;
}

