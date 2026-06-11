#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    long n;
    cin >> n;

    vector<long> p(n);
    rep(i,n) {
        cin >> p.at(i);
    }

    long count=1;
    long min=p.at(0);
    for (long i=1; i<n; ++i) {
        if (min>p.at(i)) {
            min=p.at(i);
            count++;
        }
    }

    cout << count << endl;
    
    return 0;
}