#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll T1,T2;
    cin >> T1 >> T2;
    vector<ll> A(2),B(2);
    cin >> A[0] >> A[1];
    cin >> B[0] >> B[1];
    if(A[0]<B[0]){
        swap(A,B);
    }
    // cerr <<"A0=" << A[0] <<", A1=" <<A[1] << endl;
    ll firstHalf = (A[0]-B[0]) * T1;
    ll lastHalf = (A[1] -B[1]) *T2;
    ll diff =firstHalf +lastHalf;
    // cerr <<"diff=" << diff << endl;
    if(diff==0){
        cout << "infinity" << endl;
        return 0;
    }
    if(diff>0){
        cout << 0 << endl;
        return 0;
    }
    // cerr <<"target =" << (A[0]-B[0])*T1 << endl;
    ll ans = firstHalf/(-diff) +1;
    ans *=2;
    //最初の一回分は引く。
    --ans;
    //最後ちょうど一回出会う場合は回数が通常より少なくなる。
    if(firstHalf %(-diff) ==0){
        --ans;
    }
    cout << ans << endl;
    return 0;
}