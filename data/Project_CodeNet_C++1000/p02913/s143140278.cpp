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
#define REV(x) reverse(ALL((x)))
#define pb push_back

vec z_algorithm(string S)
{
    ll N = SZ(S);
    vec Z(N, 0);
    ll i = 1, j = 0, k;
    
    Z[0] = N;
    while(i < N) {
        while(i + j < N && S[j] == S[i+j]) ++j;
        Z[i] = j;

        if(j == 0) {
            ++i;
            continue;
        }

        k = 1;
        while(k < j && k + Z[k] < j) {
            Z[i+k] = Z[k];
            ++k;
        }

        i += k;
        j -= k;
    }

    return Z;
}

int main()
{
    ll N;
    string S;
    cin >> N;
    cin >> S;

    string T;
    vec Z;
    ll m = 0;
    REP(i,0,N) {
        T = S.substr(i);
        Z = z_algorithm(T);
        REP(j,1,SZ(Z)) {
            if(Z[j] <= j) m = MAX(m,Z[j]);
        }
    }
    PR(m);

    return 0;
}

/*

*/