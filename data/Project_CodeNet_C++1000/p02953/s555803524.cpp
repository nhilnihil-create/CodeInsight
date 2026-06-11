#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    vector<int> A(N,0);
    bool check = 1;
    for(int i = 0; i < N; i++) {
        cin >> A.at(i);
    }
    reverse(A.begin(),A.end());
    int temp = A.at(0);
    for(int i = 0; i < N; i++) {
        if(A.at(i) - 1 > temp) {
            check = 0;
            break;
        }
        temp = min(temp, A.at(i));
    }
    if(check) {
    cout << "Yes" << endl;
    } else {
    cout << "No" << endl;
    }

    return 0;
}