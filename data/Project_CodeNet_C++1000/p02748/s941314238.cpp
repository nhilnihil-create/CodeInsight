#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
const ll mod = 1e9+7;
int inf = 1000000000; //10e9

int main(){

    int a, b, m;
    cin >> a >> b >> m;
    
    vector<int> mat_a(a);
    vector<int> mat_b(b);
    rep(i,a) cin >> mat_a[i];
    rep(i,b) cin >> mat_b[i];

    int ans = 0, x, y, c, tmp_ans=inf;
    rep(i,m){
        cin >> x >> y >> c;
        int coupon = mat_a[x-1] + mat_b[y-1] - c;
        tmp_ans = min(coupon,tmp_ans);
    }
    int min_cost = 
        *min_element(mat_a.begin(),mat_a.end()) +
        *min_element(mat_b.begin(),mat_b.end());
    ans = min(min_cost,tmp_ans);

    cout << ans << endl;

    return 0;

}