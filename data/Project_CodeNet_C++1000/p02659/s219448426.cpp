#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;
typedef int64_t ll;

int main() {
    ll A, D;
    string B, C;
    cin >> A >> B;
    C += B.at(0);
    C += B.at(2);
    C += B.at(3);
    D = stoi(C);
    cout << A * D /100 << endl;
}