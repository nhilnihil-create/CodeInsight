#include <bits/stdc++.h>
#define ALL(A) (A).begin(),(A).end()
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)

const ll mod = 1e9+7;
const ll INF = -1*((1LL<<63)+1);
const int inf = -1*((1<<31)+1);

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(20);
    int N;
    cin >> N;
    string S;
    cin >> S;
    rep(i,2*N){
        if(i%2==0){
            S[i] == 'W'?S[i]='B':S[i]='W';
        }
    }
    ll ans = 1;
    ll R = 0,L = 0;
    rep(i,2*N)if(S[i]=='W')R++;
    if(R!=N)ans = 0;
    R = 0;
    rep(i,2*N){
        if(S[i]=='W')L++;
        else {
            ans *= L;
            L--;
            ans %= mod;
        }
    }
    for(ll i = 0;i<N;i++){
        ans *= i+1;
        ans %= mod;
    }
    cout << ans << endl;
}