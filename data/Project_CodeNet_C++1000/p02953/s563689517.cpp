#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;

#define INF (1LL << 60)
#define MOD 1000000007

#define REP(i,m,n) for(ll (i)=(m),i_len=(n);(i)<(i_len);++(i))
#define FORR(i,v) for(auto (i):v)
#define ALL(x) (x).begin(), (x).end()
#define PR(x) cout << (x) << endl
#define PS(x) cout << (x) << " "
#define SZ(x) ((ll)(x).size())
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define pb push_back
#define mp make_pair

int main()
{
    ll N;
    cin >> N;
    vec H(N);
    REP(i,0,N) cin >> H[i];

    bool f = false, g = true;;
    REP(i,0,N-1) {
        if(H[i] < H[i+1]) f = false;
        else if(H[i] == H[i+1]) continue;
        else if(H[i] - H[i+1] == 1) {
            if(!f) f = true;
            else {
                g = false;
                break;
            }
        }
        else {
            g = false;
            break;
        }
    }
    if(g) PR("Yes");
    else PR("No");

    return 0;
}

/*



*/