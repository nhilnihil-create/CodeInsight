#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    string c;
    cin >> n >> c;
    int r = 0, a = 0;
    for (auto x : c) if (x == 'R') r++;
    for (int i=0; i<r; i++) if (c[i] == 'R') a++;
    cout << r - a << endl;
    return 0;
}