#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    
    int X;
    cin >> X;
    rep(i,8){
        int v = 200;
        if((400+v*i <= X) && (599+v*i >= X)){
            cout << 8 - i << endl;
            break;
        } 
    }

    return 0;
}