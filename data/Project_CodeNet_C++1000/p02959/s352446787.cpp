#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N+1), B(N), C(N+1);
    for(int i = 0; i < N+1; i++){
        cin >> A.at(i);
    }
    for(int i = 0; i < N; i++){
        cin >> B.at(i);
    }
    C.at(0) = A.at(0);
    C.at(1) = A.at(1);
    ll ans = 0;
    for(int i = 0; i < N; i++){
        if(C.at(i) + A.at(i+1) <= B.at(i)){
            C.at(i+1) = 0;
            ans += C.at(i) + A.at(i+1);
        }
        else{
            if(B.at(i) >= C.at(i)){
            C.at(i+1) = (C.at(i) + A.at(i+1)) - B.at(i);
            ans += B.at(i);
            }
            else{
                C.at(i+1) = A.at(i+1);
                ans += B.at(i);
            }
        }
    }
    cout << ans << endl;
}