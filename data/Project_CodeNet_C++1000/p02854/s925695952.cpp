#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i=0; i<N; i++) cin >> A.at(i);

    vector<ll> sum(N);
    sum.at(0) = A.at(0);
    for (int i=1; i<N; i++) sum.at(i) = sum.at(i-1) + A.at(i);

//    for (int i=0; i<N; i++) cout << sum.at(i) << " ";   //  debug
//    cout << endl;                                       //  debug

    vector<ll> lsum(N);
    vector<ll> rsum(N);
    ll dif = 0, ans = 1e18;
    for (int i=0; i<N; i++){
        dif = 0;
        lsum.at(i) = sum.at(i);
        rsum.at(i) = sum.at(N-1) - sum.at(i);

        dif = abs(rsum.at(i) - lsum.at(i));
        ans = min(dif, ans);         
    }

    cout << ans << endl;
    return 0;
}