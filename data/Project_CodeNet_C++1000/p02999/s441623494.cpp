#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A,X;
    cin >> A >> X;

    if (X > A) {
        cout << "0" << endl;
    }

    else if (X <= A) {
        cout << "10" << endl;
    }
    return 0;
}