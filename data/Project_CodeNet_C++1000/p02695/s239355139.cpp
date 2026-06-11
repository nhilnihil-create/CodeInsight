#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define int long long
#define ll long long 
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define pb push_back
#define rep(i, a, b) for(int i = a; i < b; i++)
#define repr(i, a, b) for(int i = a - 1; i >= b; i--)
#define iter(m) for(auto it = m.begin(); it != m.end(); it++)
#define iterr(m) for(auto it = m.rbegin(); it != m.rend(); it++)
#define N 500500
#define PI 3.14159265358979323846264338327950L
#define speed ios_base :: sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll mx = 0;
ll n, m, t;
int cnt = 0;
vector<vector<ll>> dataa;
vector<ll> v;
void solve() {
    ll sum = 0;
    for(int i = 0; i < t; i++) {
        if(v[dataa[i][1] - 1] - v[dataa[i][0] - 1] == dataa[i][2]) {
            sum += dataa[i][3];
        }
    }
    mx = max(mx, sum);
}
void rec(int ind) {
    if(ind == n) {
        solve();
        return;
    } else {
        if(ind == 0) {
            for(int i = 1; i <= m; i++) {
                v[ind] = i;
                rec(ind + 1);
            }
        }
        for(int i = 0; i <= m; i++) {
            v[ind] = v[ind - 1] + i;
            if(v[ind] > m) return;
            rec(ind+1);
        }
    }
}
signed main(){
   speed;
   cin >> n >> m;
   v = vector<int> (n); 
   cin >> t;
   dataa = vector<vector<int>> (t, vector<int> (4));
   rep(i, 0, t) {
       int a, b, c, d;
       cin >> a >> b >> c >> d;
       dataa[i][0] = a;
       dataa[i][1] = b;
       dataa[i][2] = c;
       dataa[i][3] = d;
   }
    rec(0);
    cout << mx;
}
