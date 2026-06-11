#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a, b, s1, s2;
    cin >> a >> b;
    if(a < b) {
        for(int i = 0; i < b; i++)
            cout << a;
    } else {
        for(int i = 0; i < a; i++)
            cout << b;
    }

    return 0;
}
