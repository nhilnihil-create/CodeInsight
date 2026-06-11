#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    int n;
    cin >> n;

    int N = n % 10;

    if (N==2||N==4||N==5||N==7||N==9) {
        cout << "hon" << endl;
    }
    else if (N==3) {
        cout << "bon" << endl;
    }
    else {
        cout << "pon" << endl;
    }

    
    return 0;
}