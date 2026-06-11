#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll N;
    cin >> N;
    vector<ll> A(N+1);
    vector<ll> B(N);
    ll cnt = 0;
    for(int i=0;i<N+1;i++) {
        cin >> A.at(i);
    }
    for(int i=0;i<N;i++) {
        cin >> B.at(i);
    }
    for(int i=0;i<N;i++) {
        if(A.at(i)-B.at(i) >= 0) {
            cnt += B.at(i);
        }else{
            cnt += A.at(i);
            if(A.at(i+1) - abs(A.at(i)-B.at(i)) >= 0) {
                cnt += abs(A.at(i)-B.at(i));
                A.at(i+1) = A.at(i+1) - abs(A.at(i)-B.at(i));
            }else{
                cnt += A.at(i+1);
                A.at(i+1) = 0;
            }
        }
    }
    cout << cnt << endl;
}