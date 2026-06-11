#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> H(N);
    for(int i = 0; i < N; i++){
        cin >> H.at(i);
    }
    vector<bool> C(N,true);
    for(int i = 0; i < M; i++){
        ll A, B;
        cin >> A >> B;
        if(H.at(A-1) < H.at(B-1)){
            C.at(A-1) = false;
        }else if(H.at(A-1) == H.at(B-1)){
            C.at(B-1) = false;
            C.at(A-1) = false;
        }
        else{
            C.at(B-1) = false;
        }
    }
    ll ans = 0;
    for(int i = 0; i < N; i++){
        if(C.at(i) == true) ans++;
    }
    cout << ans << endl;
}