#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ans(s.size(),0);
    int cnt = 0;
    rep(i,n){
        if(s[i] == 'L'){
            ans[i] += cnt/2;
            ans[i-1] += (cnt+1)/2;
            cnt = 0;
        }
        if(s[i] == 'R') cnt++;
    }
    cnt = 0;
    for(int i = n-1; i >= 0; i--){
        if(s[i] == 'R'){
            ans[i] += cnt/2;
            ans[i+1] += (cnt+1)/2;
            cnt = 0;
        }
        if(s[i] == 'L') cnt++;
    }
    rep(i,n) cout << ans[i] << endl;
    return 0;
}