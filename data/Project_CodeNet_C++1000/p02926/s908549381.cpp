#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;



int main(){
    int n;cin >> n;
    vector<pair<double,P>> v;
    for (int i = 0; i < n; i++) {
        int x,y;cin >> x >> y;
        if(!x&&!y) continue;
        v.pb(mp(atan2(x,y),mp(x,y)));
    }
    sort(ALL(v));
    vector<LL> xcum(2*v.size()+1,0),ycum(2*v.size()+1,0);
    for (int i = 0; i < 2*v.size(); i++) {
        xcum[i+1] = xcum[i] + v[i%v.size()].sc.fs;
        ycum[i+1] = ycum[i] + v[i%v.size()].sc.sc;
    }
    double ans = 0.0;
    for (int i = 0; i <= v.size(); i++) {
        for (int j = i+1; j-i <= v.size(); j++) {
            LL xx = xcum[j] - xcum[i];
            LL yy = ycum[j] - ycum[i];
            ans = max(ans, sqrt(xx*xx+yy*yy));
        }
    }
    cout << setprecision(30) << ans << endl;
    return 0;
}

