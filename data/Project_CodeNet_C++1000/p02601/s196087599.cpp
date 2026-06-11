#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b,c;
    cin >> a >> b >> c;
    int k;
    cin >> k;
    while(b<=a) {
        b*=2;
        k--;
    }
    while(c<=b) {
        c*=2;
        k--;
    }
    if(k>=0)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
