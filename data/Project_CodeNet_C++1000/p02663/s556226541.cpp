#include <bits/stdc++.h>
using namespace std;

int main(){
    int h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    if(m2 < m1){
        m2 += 60;
        h2 -= 1;
    }
    cout << (h2 - h1) * 60 + (m2 - m1) - k << endl;
    return 0;
}