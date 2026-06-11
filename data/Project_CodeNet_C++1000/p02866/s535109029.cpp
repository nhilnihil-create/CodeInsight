#include <bits/stdc++.h>
using namespace std;

using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_; i--)
#define REP(i, n) FOR(i, 0, n)
#define IREP(i, n) IFOR(i, 0, n)

int main()
{
    lint const mod =998244353;
    lint n;cin >> n;
    map<int, int> mp;
    int max_d = 0;
    REP(i,n){
        int d;
        cin >> d;
        int tmp = mp[d];
        mp[d] = mp[d] + 1;
        max_d = max(max_d, d);
        if(i!=0&&d==0){
            cout << 0 << "\n";
            return 0;
        }
    }
    lint ans=mp[0];
    if (mp[0] != 1){
        cout << 0 << "\n";
        return 0;
    }
    FOR(i,1,max_d + 1){
        if(mp[i]==0){
                cout << 0 << "\n";
                return 0;
        }
        REP(j,mp[i]){
            ans = ans * mp[i-1] % mod;
        }
    }
    cout << ans << "\n";
    return 0;
}