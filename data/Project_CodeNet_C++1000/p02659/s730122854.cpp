#include <bits/stdc++.h>


using namespace std;


using ll = long long;

int main(void) {
    ll A;
    string B;
    cin >> A >> B;

    ll ans = 0;
    ll pi = B.find(".");
    ll B_int = atoll(B.substr(0, pi).c_str());
    ll B_deci = atoll(B.substr(pi + 1).c_str());

    ans += A * B_int;
    ans += A * B_deci / 100;
    cout << ans << endl;
}
