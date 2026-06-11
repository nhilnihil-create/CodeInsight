#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main() {
    SPEED;
    int a;
    cin >> a;
    if (a%2 == 0) {
        cout << fixed << setprecision(9) << 0.5 << endl;
    } else {
        double temp = a/2;
        temp+=1;
        temp/=a;
        cout << fixed << setprecision(9) << temp << endl;
    }
    return 0;
}