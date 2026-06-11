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
    ll K;
    cin >> K;

    ll c = 0, L;
    queue<ll> Q;
    REP(i,1,10) Q.push(i);
    ll v;
    while(c < K) {
        v = Q.front(); Q.pop();
        ++c;
        if(v % 10 == 0) {
            Q.push(v * 10); 
            Q.push(v * 10 + 1);
        }
        else if(v % 10 == 9) {
            Q.push(v * 10 + 8); 
            Q.push(v * 10 + 9);
        }
        else {
            Q.push(v * 10 + v % 10 - 1); 
            Q.push(v * 10 + v % 10), 
            Q.push(v * 10 + v % 10 + 1);
        }
    }
    
    PR(v);


    return 0;
}

/*



*/