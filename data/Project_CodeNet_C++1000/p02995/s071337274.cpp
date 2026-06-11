#include <bits/stdc++.h>
#define rep(i , n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main() {
    ll A , B , C , D;
    cin >> A >> B >> C >> D;
    ll X = B - (B / C + B / D - B / lcm(C , D));
    ll Y = A - 1 - ((A - 1) / C + (A - 1) / D - (A - 1) / lcm(C , D));
    cout << X - Y << endl;
}