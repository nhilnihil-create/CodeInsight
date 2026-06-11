#include <iostream>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
using ll = long long;

using namespace std;



int main() {
    int n;
    cin >> n;
    int l = 0, r = n;
    while(r-l > 1) {
        int m = (r+l)/2;
        if(m*1.08 < n) l = m;
        else r = m;
    }
    double p = r * 1.08;
    if(p >= n && p < n+1) cout << r << endl;
    else cout << ":(" << endl;

    return 0;
}
