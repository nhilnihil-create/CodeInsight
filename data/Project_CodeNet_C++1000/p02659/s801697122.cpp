#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main (){/* 
    ll A;
    double B;
    cin >> A >> B;
    B *= 100;
    ll b = B;
    ll ans = A*b/100;
    cout << ans << endl;
 */
/* 力技
    ll A;
    string B;
    cin >> A >> B;
    if(B.size() == 1) {
        cout << A*(B.at(0) - '0') << endl;
    } else if(B.size() == 4){
        ll temp = 100*(B.at(0) - '0') + 10*(B.at(2) - '0') + B.at(3) - '0';
        cout << (A*temp)/100 << endl;
    } else {
        ll temp = 100*(B.at(0) - '0') + 10*(B.at(2) - '0');
        cout << (A*temp)/100 << endl;
    } */
    ll A;
    double B;
    cin >> A >> B;
    B *= 100;
    B += 0.5;
    ll b = B;

    cout << A*b/100 << endl;
}
