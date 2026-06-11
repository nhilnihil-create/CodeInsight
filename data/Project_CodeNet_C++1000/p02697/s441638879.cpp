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

int main()
{
    ll N, M;
    cin >> N >> M;

    if(N % 2 == 0) {
        ll B = (N + 2) / 2;
        ll W = N - 1;
        ll left = 0, right = N-2, cnt = 0;
        while(W > B && cnt < M) {
            cout << left+1 << " " << right+1 << endl;
            ++left; --right;
            W = right - left + 1;
            ++cnt;
        }
        --right;
        while(cnt < M) {
            cout << left+1 << " " << right+1 << endl;
            ++left; --right;
            ++cnt;
        }
    }
    else {
        ll left = 0, right = N-2, cnt = 0;
        while(cnt < M) {
            cout << left+1 << " " << right+1 << endl;
            ++left; --right;
            ++cnt;
        }
    }
    return 0;
}

/*






*/