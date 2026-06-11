#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
typedef long long ll;

using namespace std;

int main(){

    int N,K;
    cin>>N>>K;
    ll h[200000]={0};
    REP(i,N){
        cin>>h[i];
    }
    sort(h,h+N,greater<int>());
    REP(i,K){
        h[i]=0;
    }
    ll ans=0;
    REP(i,N){
        ans+=h[i];
    }
    cout << ans << endl;

    return 0;
}