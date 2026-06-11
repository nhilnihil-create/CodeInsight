#include <bits/stdc++.h>

using namespace std;



void solver() {
    char x;
    cin >> x;

    if (x == tolower(x)) {
        cout << "a";
    }
    else {
        cout << "A";
    }
}

int main() {

    ios_base :: sync_with_stdio(0); cin.tie(NULL);

    int t = 1;
    //cin >> t;
    
    while(t--)
        solver();

    return 0;
}