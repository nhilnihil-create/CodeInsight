#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
    string s,t;
    cin>>s>>t;
    int ans=0;
    rep(i,3) if(s[i]==t[i]) ans++;
    printf("%d\n",ans);
    return 0;
}