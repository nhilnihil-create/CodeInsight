#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;
using P = pair<int, int>;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int n;

int f(char c){
    return (int)(c - '0');
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    while(1){
        cin >> n;
        if(n == 0) break;
        vector<int> imos(60*60*24+100, 0);
        
        REP(i, n){
            string s1, s2;
            cin >> s1 >> s2;
            int t1 = 0, t2 = 0;
            t1 += f(s1[0]) * 36000 + f(s1[1]) * 3600 + f(s1[3]) * 600 + f(s1[4]) * 60 + f(s1[6]) * 10 + f(s1[7]);
            t2 += f(s2[0]) * 36000 + f(s2[1]) * 3600 + f(s2[3]) * 600 + f(s2[4]) * 60 + f(s2[6]) * 10 + f(s2[7]);
            imos[t1]++; imos[t2]--;
        }
        REP(i, 60*60*24+10) imos[i+1] += imos[i];
        int ans = 0;
        
        REP(i, 60*60*24+1) ans = max(ans, imos[i]);
        cout << ans << endl;
    }
}

