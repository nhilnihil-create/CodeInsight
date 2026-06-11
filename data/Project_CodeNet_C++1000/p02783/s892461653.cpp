#include <iostream>
#include <cmath>
#include <ctgmath>
using namespace std;

int main() {
    int h, a;
    cin >> h >> a;
    int i = 0;
    int j = 0;
    while(i < h){
        h = h - a;
        j++;
        if(i >= h){
            cout << j;
        }
    }

    return 0;
}