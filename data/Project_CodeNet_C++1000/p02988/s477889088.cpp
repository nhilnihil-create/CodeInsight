#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    int ans = 0;
    for(int i=1; i<p.size()-1; i++){
        if((p[i-1]-p[i])*(p[i+1]-p[i])<0) ans++;
    }
    cout << ans << endl;
    return 0;
}