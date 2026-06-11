#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    // cinを高速にするためのおまじない
    cin.tie(0);
    ios::sync_with_stdio(false);

    /////////////////////
    // Write code below /
    long long int N,D,X,Y;
    int count = 0;
    cin >> N >> D;
    D = D*D;
    for(int i = 0; i<N;i++){
        cin >> X >> Y;
        X = X*X;
        Y = Y*Y;
        if(D >= X+Y) count++;
    }
    cout << count++;
    /////////////////////

    return 0;
}