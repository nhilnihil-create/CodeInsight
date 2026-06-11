#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define ALL(c) (c).begin(),(c).end()

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

#define INF 1e18

int main(){
    int N,K; cin>>N>>K;
    V<int> P(N),C(N);
    rep(i,N)cin>>P.at(i),--P.at(i);
    rep(i,N)cin>>C.at(i);

    ll res = -INF;

    rep(i,N){
        int v = i;
        ll cycle_sum = 0;
        int cycle_cnt = 0;

        while(1){
            cycle_cnt++;
            cycle_sum += C.at(v);
            v = P.at(v);
            if(v==i)break;
        }

        ll path = 0;
        int cnt = 0;

        while(1){
            cnt++;
            path += C[v];

            if(cnt>K)break;

            int num = (K-cnt) / cycle_cnt;
            ll score = path + max(0ll, cycle_sum) * num;
            chmax(res,score);

            v = P.at(v);
            if(v==i)break;
        }
    }

    cout<<res<<endl;
}