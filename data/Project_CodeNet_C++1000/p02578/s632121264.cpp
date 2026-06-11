#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
const int INF = 1001001001;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    ll ans=0;
    rep(i,N) cin >> A.at(i);
    int maxtmp=0;
    rep(i,N){
        maxtmp = max(maxtmp, A.at(i));
        ans += maxtmp - A.at(i); 
    }
    cout << ans << endl;
    return 0;
}