#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
#define PI 3.14159265358979323846264338327950
int main () {
    int a,b,c;
    cin >> a >> b >> c;
    bool k = false ;
    if ( a == b && c != a){
        k = true;
    }
    if ( a == c && c != b){
        k = true;
    }
    if ( c == b && c != a){
        k = true;
    }
    if (k){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}

