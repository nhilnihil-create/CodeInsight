#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rep_ll(i,n) for(ll i = 0; i < (ll)(n); i++)
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
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll cnt=0;
    map<int,int> mp;
    rep(j, n){
        int j_aj=j-a[j];
        int i_p_ai=j+a[j];
        cnt += mp[j_aj];
        mp[i_p_ai]++;
    }
    cout << cnt;
}