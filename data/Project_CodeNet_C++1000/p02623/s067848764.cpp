#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define ALL(A) (A).begin(), (A).end()
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using Graph = vector<vector<int>>;

int main()
{
    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N), B(M);
    rep(i, N) cin >> A.at(i);
    rep(i, M) cin >> B.at(i);
    vector<ll> SA(N), SB(M);
    rep(i, N)
    {
        if (i == 0)
            SA[0] = A[0];
        else
        {
            SA[i] = A[i] + SA[i - 1];
        }
    }
    rep(i, M)
    {
        if (i == 0)
            SB[0] = B[0];
        else
        {
            SB[i] = B[i] + SB[i - 1];
        }
    }

    ll res = 0;
    auto iter1 = upper_bound(ALL(SA), K);
    ll tmp1 = iter1-1 - SA.begin();//return index
    ll tmpres = 0;

    for (int i = tmp1; i >= -1; i--)
    {
        tmpres = 0;
        ll tmpK = K;
        if(i>=0){
            tmpK = K - SA[i];
            tmpres = i+1;
        }

        auto iter2 = upper_bound(ALL(SB), tmpK);
        int tmp2 = iter2 - SB.begin();
        tmpres += max(0,tmp2);
        res = max(res,tmpres);
        
    }
    cout << res << endl;
}
