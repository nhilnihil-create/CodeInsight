#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    vector<int> A(N,0);
    vector<int> a(N,0);
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    a = A;
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int FA = a.at(0);
    int SA = a.at(1);

    for(int i = 0; i < N; i++) {
        if(A.at(i) == FA) {
            cout << SA << endl;
        } else {
            cout << FA << endl;
        }
    }



    return 0;
}