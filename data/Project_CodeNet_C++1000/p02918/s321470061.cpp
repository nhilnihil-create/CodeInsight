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
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    if(S[0] == 'R') {
        REP(i,0,N) {
            if(S[i] == 'L') S[i] = 'R';
            else S[i] = 'L';
        }
    }

    char prev = 'L';
    REP(i,1,N) {
        if(prev == 'L' && S[i] == 'R') K--;
        if(K < 0) break;
        prev = S[i];
        S[i] = 'L';
    }

    ll cnt = 1, g = 1;;
    prev = S[0];
    REP(i,1,N) {
        if(S[i] != prev) ++cnt;
        prev = S[i];
    }
    PR(SZ(S)-cnt);
    

    return 0;
}

/*

            

*/