#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;

#define INF (1LL << 60)
#define MOD 1000000007
#define PI 3.14159265358979323846

#define REP(i,m,n) for(ll (i)=(m),(i_len)=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ASC(x) sort(ALL((x)))
#define DESC(x) sort(ALL((x)),greater<ll>())
#define pb push_back

int main()
{
    ll N;
    string S;
    cin >> N;
    cin >> S;

    ll R = 0, G = 0, B = 0;
    REP(i,0,N) {
        if(S[i] == 'R') ++R;
        else if(S[i] == 'G') ++G;
        else if(S[i] == 'B') ++B;
    }

    ll cnt = R * G * B;
    REP(i,0,N-2) {
        REP(j,i+1,N-1) {
            ll k = 2 * j - i;
            if(k < N) {
                if(S[i] != S[j] && S[j] != S[k] && S[k] != S[i]) --cnt;
            }
        }
    }
    PR(cnt);

    return 0;
}

/*



*/