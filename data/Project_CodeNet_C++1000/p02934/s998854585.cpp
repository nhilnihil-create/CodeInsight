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
    int n;
    cin >> n;
    vector<long double> a(n);
    rep(i, 0, n) cin >> a[i];

    long double total=0;
    rep(i, 0, n) total+=1/a[i];
    total=1/total;
    cout << fixed << setprecision(6) << total;
}