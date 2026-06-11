#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define rep(i,n) for(ll i=0;i<(ll)n;i++)

int main(){
    int N,K; cin >> N >> K;
    vector<long double> P(N+1,0) , S(N+1,0);
    long double res=0;
    rep(i,N){
        double x; cin >> x;
        P[i]=(1+x)/2;
        S[i+1]=S[i]+P[i];
    }
    for(int i=0;i+K<=N;i++){
        res = max(res, (S[i+K]-S[i]) );
    }

    cout << fixed << setprecision(15) << res << endl; 
}