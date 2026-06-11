#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>>a(m);
    rep(i,n) {
        int A,B;
        cin >> A >> B;
        if(A > m) continue;
        // cout << m-A << endl;
        a[m-A].push_back(B);
    }
    priority_queue<int> q;
    ll ans = 0;
    
    for(int i = m-1;i>=0;i--) {
            for(auto x : a[i]) {
                q.push(x);
            }
        if(!q.empty()) {
            ans += q.top();q.pop();
        }
    }
    cout << ans << endl;
}