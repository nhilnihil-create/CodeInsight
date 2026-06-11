#include <bits/stdc++.h>          
using namespace std;         
typedef long long ll;      

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N+1);
    vector<ll> B(N);

    for (ll i=0; i<N+1; i++) {
        cin >> A.at(i);
    }
    for (ll i=0; i<N; i++) {
        cin >> B.at(i);
    }

    ll count = 0;
    for (ll i=0; i<N; i++) {
        if (A.at(i) >= B.at(i)) {
            count += B.at(i);
        }
        else {
            count += A.at(i);
            if (A.at(i+1) >= B.at(i)-A.at(i)) {
                count += B.at(i)-A.at(i);
                A.at(i+1) -= B.at(i)-A.at(i);
            }
            else {
                count += A.at(i+1);
                A.at(i+1) = 0;
            }
        }
    }

    cout << count << endl;
}