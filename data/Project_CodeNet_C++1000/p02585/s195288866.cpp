#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const ll mod = 1000000007;
const ll INF = 1e+14;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG

int main(){
    int N,K;
    cin>>N>>K;
    vector<int> P(N), C(N);
    rep(i,N) cin>>P[i] , --P[i];//１始まりが想定されているので1下げとく。
    rep(i,N) cin>>C[i];

    ll ans=-INF;

    rep(i,N){
        int v=i;
        ll cycle_sum=0;
        ll cycle_cnt=0;

        while(true){   //動いてから得点足し始めるからまずcnt++しとく
            cycle_cnt++;
            cycle_sum+=C[v];
            v=P[v];
            if(v==i) break;
        }
        ll path=0;
        ll cnt=0;
        while(true){
            cnt++;
            path+=C[v];
            if(cnt>K) break;
            int num=(K-cnt)/cycle_cnt;
            ll score =path+max(0ll,cycle_sum)*num;
            ans =max(ans, score);
            v=P[v];
            if(v==i) break;


        }
    }

    cout<<ans<<endl;

}