#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;

int main(){
    ll A;
    string B;
    cin >> A >> B;
    ll B100 = (B[0] - '0') * 100 + (B[2] - '0') * 10 + (B[3] - '0');
    cout << A * B100 / 100 << endl;
    return 0;
}