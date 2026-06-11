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
    int N;
    cin >> N;
    if(N%1000 == 0){
        N = 0;
    }else{
        N = 1000 - (N%1000);
    }
    cout << N << endl;
    /////////////////////


    return 0;
}
