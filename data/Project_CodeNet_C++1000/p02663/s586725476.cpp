#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){

    int a1, a2, b1, b2, k;
    cin >> a1 >> a2 >> b1 >> b2 >> k;

    int diff = (b1*60) + b2 - (a1*60) - a2;

    int res = diff - k;

    cout << res;

    return 0;

}