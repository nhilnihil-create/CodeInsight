#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef pair<int,int> P;
typedef long long ll;
const int INF = 1001001001;
const ll INFL = 1e17;
const int MOD = 1e9+7;


int main(){
    int n;
    cin >> n;
    vector<int> L(n);
    rep(i,n) cin >> L[i];
    sort(L.begin(),L.end());
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int now = L[i]+L[j];
            int r = distance(L.begin(),lower_bound(L.begin(),L.end(),now));
            int l = j+1;
            int dist = r-l;
            ans += dist;
        }
    }
    cout << ans << endl;
    return 0;
}