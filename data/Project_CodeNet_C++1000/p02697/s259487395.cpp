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
    vector<P>ans;
    if(n%2) {
        for(int l = 1,r = n-1;l < r;l++,r--) {
            ans.push_back({r,l});
        }
    } else {
        bool flag = false;
        for(int l  = 1, r = n-1; l < r;l++,r--) {
            if(!flag && r-l <= n/2) {
                r--;
                flag = true;
            }
            ans.push_back({r,l});
        }
    }
    rep(i,m) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}