#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int inf = 1001001001;
 
int main(){

    ll N;
    cin >> N;
    vector<ll> weight(N);
    rep(i,N){
        cin >> weight.at(i);
    }
    ll t=INF;
    for(ll i=0; i<N; i++){
        ll suma=0;
        ll sumb=0;
        for(ll j=0; j<i+1; j++){
            suma+=weight.at(j);
        }
        for(ll k=i+1; k<N; k++){
            sumb+=weight.at(k);
        }
        if(abs(suma-sumb)<t){
            t=abs(suma-sumb);
        }
    }

    cout << t << endl;
}