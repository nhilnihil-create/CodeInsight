#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;
int inf = 1000000000; //10e9
 
int main() {

    int n;
    cin >> n;
    vector<int> d(n);
    rep(i,n) cin >> d[i];

    sort(d.begin(),d.end());
    int ans = d[n/2] - d[n/2-1];

    cout << ans << endl;

    return 0;

}