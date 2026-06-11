#include <bits/stdc++.h>
#define REP(i,n) for (int i=0; i<(n); ++i)
#define REPR(i,n,m) for (int i=(n); i>=(m); --i)
using namespace std;
using LL = long long;
using LD = long double;
using PLL = pair<long long, long long>;
using PLD = pair<long double, long double>;
using VLL = vector<long long>;
using VLD = vector<long double>;
using VPLD = vector<PLD>;

const int INF = numeric_limits<int>::max();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int K,N;
    cin>>N>>K;
    double p[N];
    vector<double>t(N+1,0);
    for(int i=0;i<N;i++){
        cin>>p[i];
        t[i+1]=t[i]+p[i]*(0.5)+0.5;
        //cout<<i<<" "<<t[i]<<endl;
    }
    double maxp=0;
    for(int i=0;i<N-K+1;i++){
        maxp=max(maxp,t[i+K]-t[i]);
    }
    cout<<setprecision(18)<<maxp<<endl;
    return 0;

}