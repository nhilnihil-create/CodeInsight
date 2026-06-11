#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;
using Graph = vector<vector<int>>;

int main(){
    int M,N;
    cin >> N >> M;
    int s[M],c[M];
    REP(i,M) cin >> s[i] >> c[i];
    REP(i,M) s[i]--;
    int used[N];
    REP(i,N) used[i] = -1;
    bool can = true;
    if(N==1&&M==0) cout << 0 << endl;
    else if(N==1){
        REP(i,M){
            if(used[s[i]]!= -1&& used[s[i]]!=c[i]) can = false;
            else used[s[i]] = c[i];
        }
        if(!can) cout << -1 << endl;
        else cout << used[0] << endl;
    }
    else{
    REP(i,M){
        if(s[i]==0&&c[i]==0) can = false;
        if(used[s[i]] != -1 && used[s[i]]!=c[i]) can = false;
        else used[s[i]] = c[i];
    }
    if(used[0]==-1) used[0] = 1;
    if(!can) cout << -1 << endl;
    else{
        int ans = 0;
        REP(i,N){
            int d = N-i;
            d--;
            if(used[i] == -1) continue;
            else{
                ans += used[i] * pow(10,d);
            }
        }
        cout << ans << endl;
    }
    }
}