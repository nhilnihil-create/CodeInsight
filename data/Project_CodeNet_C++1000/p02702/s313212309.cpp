#include <bits/stdc++.h>

const int INF = 1e9;
const int MOD = 2019;

using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REPD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < int(b); i++)
#define FORD(i, a, b) for (int i = b - 1; i >= int(a); i--)
#define WRAP(y, x, h, w) (0 <= y && y < h && 0 <= x && x < w)

#define ALL(x) (x).begin(), (x).end()

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

ll powmod(ll n, ll x)
{
    vector<ll> vll(32);
    vll[0] = n;
    FOR(i, 1, 32)
    {
        vll[i] = (vll[i - 1] * vll[i - 1]) % MOD;
    }
    ll ret = 1;
    int cnt = 0;
    while (x > 0) {
        if (x & 1) {
            ret = (ret * vll[cnt]) % MOD;
        }
        x >>= 1;
        cnt++;
    }
    return ret;
}

int main()
{
    string s;
    cin >> s;
    vector<int> memo(s.length());
    map<int,int> mpii;
    mpii[0]++;
    REPD(i,s.length()){
        if(i==s.length()-1){
            memo[i]=s[i]-'0';
            mpii[memo[i]]++;
        }else{
            memo[i]=(memo[i+1]+(s[i]-'0')*powmod(10,s.length()-i-1))%MOD;
            mpii[memo[i]]++;
        }
    }
    ll ans=0;
    for(auto it=mpii.begin();it!=mpii.end();it++){
        ans+=(it->second)*((it->second)-1)/2;
    }
    cout<<ans<<endl;
}