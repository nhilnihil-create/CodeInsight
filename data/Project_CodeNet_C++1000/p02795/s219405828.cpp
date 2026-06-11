#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    if(a<b) swap(a,b);
    if(c%a==0) cout << c/a <<endl;
    else cout << c/a + 1 << endl;
    return 0;
}
