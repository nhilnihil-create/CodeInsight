#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll result = 1;
    for(int i=0;i<N;i++) {
        cin >> A.at(i);
    }

    if(find(A.begin(),A.end(),0) != A.end()) {
        cout << "0" << endl;
        exit(0);
    }
    for(int i=0;i<N;i++) {
        if (result > (ll)pow(10,18)/A.at(i)) {
            cout << "-1" << endl;
            exit(0);
        }
        result = result * A.at(i);
    }
    cout << result << endl;
}