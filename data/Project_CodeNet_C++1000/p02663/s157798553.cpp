#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
    int wh,wm,sh,sm,k;
    cin >> wh >> wm >> sh >> sm >>k;
    wm += wh*60;
    sm += sh*60;
    cout << sm - wm - k << endl;
}