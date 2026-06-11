#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> p(n, 0);
    rep(i, k){
        int d;
        cin >> d;
        rep(j, d){
            int a;
            cin >> a;
            p[a-1]+=d;
        }
    }
    int ans = 0;
    rep(i, n){
        if(p[i]==0) ans++;
    }
    cout << ans << endl;
    return 0;
}