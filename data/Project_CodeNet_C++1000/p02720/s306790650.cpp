#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

vector<ll>ans;
void dfs(int i,int j,ll cur) {
    if(i==10) return;
    ans.push_back(cur);
    if(j>=1)dfs(i+1,j-1,cur*10+j-1);
    dfs(i+1,j,cur*10+j);
    if(j<=8)dfs(i+1,j+1,cur*10+j+1);
}

int main() {
    int k;
    cin >> k;
    for(ll i = 1;i<=9;i++) {
        dfs(0,i,i);
    }
    sort(ans.begin(),ans.end());
    cout << ans[k-1] << endl;
}