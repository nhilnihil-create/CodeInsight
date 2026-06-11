#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i < n; i++)
typedef long long ll;
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    int p = accumulate(x.begin(), x.end(),0)/n;
    auto square = [&](vector<int> x, int p){
        int ans =0;
        rep(i,n){
            ans += pow(x[i]-p,2);
        }
        return ans;
    };
    int ans = min(square(x,p), square(x,p+1));
    cout << ans << endl;
}