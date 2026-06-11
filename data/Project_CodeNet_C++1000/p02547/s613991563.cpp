// ABC179B.cpp

#include <iostream>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
int main()
{
    int n;
    cin >> n;
    int d[110][2];
    rep(i, n) {
        cin >> d[i][0] >> d[i][1];
    }
    int i = 0;
    string ans = "No";
    // n=5 i=0,1,2,3,4 
    while(i<n-2) {
        if (d[i][0] == d[i][1]&& d[i + 1][0] == d[i + 1][1]&& d[i + 2][0] == d[i + 2][1]) {
            ans = "Yes";
            break;
        }
        i++;
    }
    cout << ans << endl;
    return 0;
}
