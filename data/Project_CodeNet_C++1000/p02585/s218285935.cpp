#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)


using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}


int main(void){
    int N,K;
    cin>>N>>K;
    V<int> P(N),C(N);
    rep(i,N)cin>>P[i],--P[i];
    rep(i,N)cin>>C[i];
    ll ans = -INF;

    rep(i,N){
        int j=i;
        ll cycle_score=0;
        int cycle_len=0;
        while(true){
            j=P[j];
            cycle_len++;
            cycle_score+=C[j];
            if(j==i)break;
        }
        int partial_len = 0;
        ll partial_score = 0;
        while(true){
            j=P[j];
            partial_len++;
            if(partial_len>K)break;
            partial_score+=C[j];
            int num = (K-partial_len)/cycle_len;
            ll score = partial_score+max(0ll,cycle_score)*num;
            chmax(ans,score);
            if(j==i)break;
        }
    }

    cout<<ans<<endl;

	return 0;
}