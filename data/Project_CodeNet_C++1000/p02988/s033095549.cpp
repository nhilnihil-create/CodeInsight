#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define VB vector<bool>
#define VP vector<pair<ll,ll>>
#define VVL vector<vector<ll>>
#define VVP vector<vector<pair<ll,ll>>>
#define PL pair<ll,ll>
#define ALL(v) (v).begin(), (v).end()

ll N;
 
int main() {
    ll N; cin>>N;
    VL p(N);
    rep(i,0,N)cin>>p[i];
    ll ans=0;
    rep(i,0,N-2){
        if(p[i]<p[i+1]&&p[i+1]<=p[i+2])ans++;
        if(p[i]>=p[i+1]&&p[i+1]>p[i+2])ans++;
    }
    cout << ans << endl;
    return 0;
}