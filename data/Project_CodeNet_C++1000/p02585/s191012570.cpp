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
    V<int> P(N);
    V<int> C(N);
    rep(i,N)cin>>P[i],--P[i];
    rep(i,N)cin>>C[i];
    ll ans = -LINF;

    rep(i,N){
        int v=i;
        int circle_cnt=0;
        ll circle_sum = 0;

        while(true){
            circle_cnt++;
            v=P[v];
            circle_sum+=C[v];
            if(v==i)break;
        }
        int cnt=0;
        ll path_sum = 0;
        
        while(true){
            cnt++;
            if(K<cnt)break;
            v=P[v];
            path_sum+=C[v];
            int num=(K-cnt)/circle_cnt;
            ll score=path_sum + num*max(0ll,circle_sum);
            chmax(ans,score);
            if(v==i)break;
        }

    }
    cout<<ans<<endl;

	return 0;
}