// 基本のinclude
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define invrep(i,n) for(int i = (int)(n); i > 0; i++)
using ll = long long;

int main() {
    int n;
    cin >> n;

    rep (i, 9){
        if (n / (i+1) < 10 && n / (i+1) > 0 && n == ((i+1) * (n / (i+1)))){
            cout << "Yes" << endl;
            return 0;
        }
    }
    
    cout << "No" << endl;
    return 0;
}