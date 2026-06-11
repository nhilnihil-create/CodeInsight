#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)



int main() {
    int m1,m2,d1,d2;

    cin >> m1 >> m2 >> d1 >> d2;

    if(m1<m2 && d1>d2){
        cout << 1;
    }
    else
    cout << 0;

}