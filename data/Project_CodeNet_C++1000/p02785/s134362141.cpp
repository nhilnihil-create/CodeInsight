#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;
using Graph = vector<vector<int>>;

int main(){
    int N,K;
    cin >> N >> K;
    vector<int> H(N);
    REP(i,N) cin >> H[i];
    sort(H.begin(),H.end());
    reverse(H.begin(),H.end());
    ll ans = 0;
    REP(i,N){
        if(i < K) continue;
        else ans += H[i];
    }
    cout << ans << endl;
}