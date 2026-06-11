#include<bits/stdc++.h>
using namespace std;

#define lld long long
#define pi pair<int,int>
#define pl pair<lld,lld>
#define mem0(x) memset(x,0,sizeof(x))
#define fillnum(x,n) fill(begin(x),end(x),n)

int n;
vector<pl> a;
lld dp[2001][2001];

lld solved(int left,int right){
    if(left+right == n) return 0;
    if(dp[left][right] != -1) return dp[left][right];
    lld maxv = max(solved(left+1,right)+a[left+right].first*abs(a[left+right].second-(lld)left),
                   solved(left,right+1)+a[left+right].first*abs(a[left+right].second-(lld)(n-1-right)));
    return dp[left][right] = maxv;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) fillnum(dp[i],-1);
    for (int i = 0; i < n; i++) {
        lld v;
        cin >> v;
        pl p = make_pair(v,(lld)i);
        a.push_back(p);
    }
    sort(a.begin(),a.end(),greater<pl>());
    cout << solved(0,0) << endl;
}