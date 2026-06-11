#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second

const ll MOD = 1e9+7;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("in.txt", "r", stdin);
    int n;
    string s;
    cin >> n >> s;
    int m = 2*n;
    vi v(m);
    rep(i,0,m) {
        int a = 0;
        if(s[i] == 'B') a++;
        a += m-1-i;
        if(a%2) {
            v[i] = -1;
        } else {
            v[i] = 1;
        }
    }
    bool flag = true;
    int d = 0;
    rep(i,0,m) {
        d += v[i];
        if(d < 0) {
            flag = false;
            break;
        }
    }
    if(d != 0) flag = false;
    if(!flag) {
        cout << 0 << '\n';
        return 0;
    }
    ll ret = 1;
    ll cnt = 0;
    per(i,0,m) {
        if(v[i] == 1) {
            ret *= cnt;
            ret %= MOD;
            cnt--;
        } else {
            cnt++;
        }
    }
    rep(i,1,n+1) {
        ret = ret * i % MOD;
    }
    cout << ret << '\n';
	return 0;
}
