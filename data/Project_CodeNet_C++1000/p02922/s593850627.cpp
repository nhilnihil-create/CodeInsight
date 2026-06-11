#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, i;
    cin >> a >> b;
    for (i=0;(a-1)*i+1<b;i++);
    cout << i << endl;
    return 0;
}
