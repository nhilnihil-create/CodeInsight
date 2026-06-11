#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define mp make_pair
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

ll N;
vector<ll> P;
vector<ll> T;

void solve(vector<ll>& x1, vector<ll>& x2){
    set<ll> index;
    index.insert(N);
    for(int p = N-1; p >= 0; p--){
        ll idx = T[p];
        auto iter = index.upper_bound(idx); 
        x1[idx] = *iter;
        auto iter2 = index.upper_bound(*iter);
        if(iter2 == index.end())
            x2[idx] = *iter;
        else
            x2[idx] = *iter2;
        index.insert(idx);
    }
}

int main(){
    cin >> N;
    P.resize(N);
    T.resize(N);
    REP(i,N){
        ll p;
        cin >> p;
        p--;
        P[i] = p;
        T[p] = i;
    }

    vector<ll> L1(N);
    vector<ll> L2(N);
    vector<ll> R1(N);
    vector<ll> R2(N);

    T.push_back(N);
    P.push_back(N);

    solve(R1, R2);

    P.pop_back();
    reverse(P.begin(), P.end());
    P.push_back(N);

    T.pop_back();
    REP(i,N){
        ll p = P[i];
        T[p] = i;
    }
    T.push_back(N);

    solve(L1, L2);
    reverse(L1.begin(), L1.end());
    reverse(L2.begin(), L2.end());
    P.pop_back();
    reverse(P.begin(), P.end());

    REP(i,N){
        L1[i] = N - L1[i];
        L2[i] = N - L2[i];
    }

    ll ans = 0;
    REP(i,N){
        ll p = P[i];
        ll add = 0;
        add += (L1[i] - L2[i]) * (R1[i] - i);
        add += (R2[i] - R1[i]) * (i - L1[i] + 1);
        add *= (p+1);
        ans += add;
        //printf("%d : %lld (%lld %lld) (%lld %lld) %lld %lld\n", i, p+1, L1[i], L2[i], R1[i], R2[i], add, ans);
        //printf("%d : %lld %lld %lld\n", i, p+1, left[i], right[i]);
    }

    cout << ans << endl;
    return 0;
}
