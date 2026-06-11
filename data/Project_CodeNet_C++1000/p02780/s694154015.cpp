#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
    double N,K; cin>>N>>K;
    vector<double> p(N);
    rep(i,N) cin>>p[i];

    double avg=0;
    for(int i=0; i<K; i++){
        avg += (p[i]*(1+p[i]))/(2*p[i]);
    }
    // cout << avg << endl;

    double max_avg=avg,ret_avg=avg;
    for(int i=0; i+K<N; i++){
        ret_avg -= (p[i]*(1+p[i]))/(2*p[i]);
        ret_avg += (p[i+K]*(1+p[i+K]))/(2*p[i+K]);
        // cout << ret_avg << endl;
        max_avg = max(max_avg, ret_avg);
    }

    cout << fixed << setprecision(15) << max_avg << endl;
}
