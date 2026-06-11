#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int L, R, d;
    cin >> L >> R >> d;
    cout << R/d - (L - 1)/d << endl;
    return 0;
}