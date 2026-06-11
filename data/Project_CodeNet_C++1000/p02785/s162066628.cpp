#include<bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i=0; i<n; i++)
#define ALL(c) c.begin(), c.end()

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> H(N);
    rep(i, N) cin >> H.at(i);
    sort(ALL(H));
    reverse(ALL(H));
    int cnt = 0;
    ll sum = 0ll;
    rep(i, N){
        if(cnt < K) cnt++;
        else sum += H.at(i); 
    }
    cout << sum << endl;
}