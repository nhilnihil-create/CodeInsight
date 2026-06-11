#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef vector<lint> vlint;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main(){
    int h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    int time = (h2 - h1) * 60 + m2 - m1;
    cout << time - k << endl;
}