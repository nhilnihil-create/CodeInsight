#include <bits/stdc++.h>
using namespace std;

int main(){
    int X;
    cin >> X;
    int i = 1;
    while(1){
        if((360 * i) % X == 0) {
            break;
        }
        i += 1;
    }
    cout << (360 * i) / X << endl;
}
