#include <bits/stdc++.h>
using namespace std;
int main(){
    int h1,h2, m1,m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int mk, hk;
    mk = k%60;
    hk = k/60;
    if(mk > m2) {
        hk++;
        m2 += 60;
    }
    cout << (h2 - hk - h1)*60 + (m2 - mk - m1) << endl;
}