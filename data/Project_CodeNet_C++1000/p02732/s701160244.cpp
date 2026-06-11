#include <bits/stdc++.h>          
using namespace std;               
typedef long long ll;

ll nC2(ll n) {
    return n*(n-1)/2;
}

int main() {

    //
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i=0; i<N; i++) {
        cin >> A[i];
    }

    // maxAを求める
    vector<ll> A_temp = A;
    sort(A_temp.begin(),A_temp.end());
    ll maxA = A_temp[N-1];

    // countベクトル（ベクトルAのi番目の数が何個あるか）
    vector<ll> count(maxA,0);
    for (ll i=0; i<N; i++) {
        count[A[i]-1]++;
    }
    /*
    cout << endl;
    for (ll i=0; i<maxA; i++) {
        cout << count[i] << endl;
    }
    cout << endl;
    */
    ll N_pair = 0;     // 全組み合わせ
    for (ll i=0; i<maxA; i++) {
        N_pair += nC2(count[i]);
    }
    /*
    cout << N_pair << endl;
    cout << endl;
    */
    vector<ll> k(N,N_pair);
    for (ll i=0; i<N; i++) {
        k[i] -= nC2(count[A[i]-1]) - nC2(count[A[i]-1]-1);
    }
    
    //
    for (ll i=0; i<N; i++) {
        cout << k[i] << endl;
    }
    
}