#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int turn = 0;
    while(a > 0 && c > 0){
        if(turn % 2 == 0) c -= b;
        if(turn % 2 == 1) a -= d;
        turn += 1;
    }
    if(a <= 0) cout << "No" << endl;
    if(c <= 0) cout << "Yes" << endl;
    return 0;
}