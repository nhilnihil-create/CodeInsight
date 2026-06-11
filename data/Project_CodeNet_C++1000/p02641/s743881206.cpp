#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using P = pair<int, int>;
int main()
{
    int x,n;
    cin >> x >> n;
    vector<bool> p(102,true);
    rep(i,n){
        int t;
        cin >> t;
        p[t]= false;
    }

    int ans = 103;
    rep(i,102){
        if(p[i] && abs(i-x) < abs(ans-x)){
            ans = i;
        }
    }
    cout << ans << endl;

return 0;
}