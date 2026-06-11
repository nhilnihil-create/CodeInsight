#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

    int main (){
        int n;
        cin >> n;
        vector<int> x(n);
        rep(i,n)cin >> x[i];
        int l=x[0],r=x[0];
        rep(i,n){
            l=min(l,x[i]);
            r=max(r,x[i]);
        }
        int ans = inf;
        for(int i=l;i<=r;i++){
            int cost =0;
            rep(j,n)cost += (x[j]-i)*(x[j]-i);
            ans = min(ans,cost);
        }

        cout << ans << endl;
return 0;

    }