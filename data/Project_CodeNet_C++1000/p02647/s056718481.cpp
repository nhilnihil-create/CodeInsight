#include <bits/stdc++.h>
#define rep(i,x,n) for(int i = x; i < (int)(n); i++)
#define rep_ll(i,x,n) for(ll i = x; i < (ll)(n); i++)
using namespace std;
typedef long long ll;
typedef unsigned long long u_ll;
typedef pair<int, int> pair_;
const long double PI = (acos(-1));
const int INF = 1001001001;
const int dx[] = {-1, 0, 1, 0}; const int dy[] = {0, -1, 0, 1};
ll mod = 1000000007;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,0,n) cin >> a[i];
    
    rep(i,0,k){
        vector<int> d(n+1, 0);//nが境界にはならないから
        rep(j,0,n){
            ll l=max(0, j-a[j]);
            ll r=min(n, j+a[j]+1);
            d[l]++; d[r]--;
        }
        rep(j,1,n) d[j]+=d[j-1];
        d.pop_back();
        swap(a, d);
        if(a==d) break;
    }
    rep(i, 0, n) cout << a[i] << " ";

    return 0;
}