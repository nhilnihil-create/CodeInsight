#include <bits/stdc++.h>
using namespace std;

int main(){
    int p, q, r;
    cin >> p >> q >> r;
    vector<int> A = {p, q, r};
    sort(A.begin(), A.end());
    cout << A.at(0) + A.at(1) << endl;
}