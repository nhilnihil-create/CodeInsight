#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1LL << 60;

//---main---------------------------------------------
int main(){
    //main
    int N;
    cin >> N;

    vector<ll> A(N);
    ll x=0;
    rep(i,N) cin >> A[i];

    for(int i = 0; i<N; i+=2) x+=A[i];
    for(int i = 1; i<N; i+=2) x-=A[i];
    
    rep(i,N-1){
        cout << x << " ";
        x = 2*A[i] - x;
    }
    cout << x << endl;

    return 0;
}