/**
*    created: 17.05.2020 12:05:05
**/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int inf =1000000000;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if(b+c>a) cout << c-a+b << endl;
    else cout << 0 << endl;
}