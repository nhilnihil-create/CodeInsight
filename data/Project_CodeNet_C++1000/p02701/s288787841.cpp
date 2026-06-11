#include <bits/stdc++.h>          
using namespace std;               
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<string> S(N);
    for (ll i=0; i<N; i++) {
        cin >> S.at(i);
    }

    //
    vector<string> S_new(N);
    sort(S.begin(),S.end());
    S_new = S;
    ll count = 1;
    for (ll i=0; i<N-1; i++) {
        if (S.at(i) != S.at(i+1)) {
            count++;
        }
    }
    cout << count << endl;
}