#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vec = vector<ll>;
using mat = vector<vec>;
using pll = pair<ll,ll>;

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
#define REV(x) reverse(ALL((x)))
#define ASC(x) sort(ALL((x)))
#define DESC(x) ASC((x)); REV((x))
#define pb push_back
#define eb emplace_back

int main()
{
    string S;
    cin >> S;

    ll N = SZ(S)+1;
    vec A(N, -1);
    A[0] = 0; A[N-1] = 0;
    for(ll j=N-2; j>=0 && S[j] == '>'; --j) A[j] = MAX(A[j],N-1-j);
    for(ll j=1; j<N && S[j-1] == '<'; ++j) A[j] = MAX(A[j],j);
    REP(i,1,N-1) {
        if(S[i-1] == '>' && S[i] == '<') {
            A[i] = 0;
            for(ll j=i-1; j>=0 && S[j] == '>'; --j) A[j] = MAX(A[j],i-j);
            for(ll j=i+1; j<N && S[j-1] == '<'; ++j) A[j] = MAX(A[j],j-i);
        }
    }

    ll sum = 0;
    REP(i,0,N) sum += A[i];
    PR(sum);
    

    return 0;
}

/*
0   1   2   3   4   5   6   7   8   9
0 < 3 > 2 > 1 > 0 < 1 < 2 > 0 < 1 < 2 < 3 < 4 < 5 > 2 > 1 > 0 < 1
  0   1   2   3   4   5   6   7   8
*/