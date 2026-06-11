#include <bits/stdc++.h>
using namespace std;
int main(void){

    string s, t, u;
    int a, b;

    cin >> s >> t;
    cin >> a >> b;

    cin >> u;

    if(s == u)
        a -= 1;
    else if (t == u)
        b -= 1;

    cout << a << ' ' << b << endl;

    return 0;
}