#include <bits/stdc++.h>
#define REP(i,s,e) for(int i=(s); i<(e);i++)
#define rep(i,n) REP(i,0,n)
#define rep1(i,n) REP(i,1,n)
#define repe(i,n) for(auto &&i:n)
#define all(v) (v).begin(),(v).end()
#define decimal fixed<<setprecision(20)
#define fastcin() cin.tie(0);ios::sync_with_stdio(false)
//#define int long long
using LL = long long;
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = 1e9;
const LL LLINF = 1e16;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

signed main(){
    fastcin();
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ans;
    vector<int> d(n, 0);
    if(n % 2 == 1){
        rep(i, m) ans.emplace_back(i, 2*m-1-i);
    }else{
        int rem = n-2*m-1;
        int l=m-1, r=m;
        rep(i, m){
            ans.emplace_back(l, r);
            if(i+1 == (m+1)/2){
                r+=rem;
            }
            l--; r++;
        }
    }
    repe(i, ans){
        cout << i.first+1 << " " << i.second+1 << endl;
    }
}