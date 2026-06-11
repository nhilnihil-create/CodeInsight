#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(i) begin(i), end(i)

int main(){
    int N;
    cin >> N;
    vector<ll> sum(N),mi(N);
    rep(i,N){
        ll a,b;
        cin >> a >> b;
        sum[i] = a+b;
        mi[i] = a -b;
    }
    sort(all(sum));
    sort(all(mi));
    cout << max(sum[N-1] - sum[0],mi[N-1] - mi[0]) << endl;
}