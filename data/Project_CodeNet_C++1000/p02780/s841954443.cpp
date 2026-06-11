#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef pair<int,int> P;
typedef long long ll;
const int INF = 1001001001;
const ll INFL = 1e17;
const int MOD = 1e9+7;


int main(){
    int n,k;
    cin >> n >> k;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    int now = 0;
    for(int i=0; i<k; i++) now += p[i];
    int ans = now;
    for(int i=k; i<n; i++){
        now = now-p[i-k]+p[i];
        ans = max(ans,now);
    }
    double output = ans;
    output = output/2.0 + 1.0/2.0*k;
    printf("%.12lf\n",output);
    return 0;
}