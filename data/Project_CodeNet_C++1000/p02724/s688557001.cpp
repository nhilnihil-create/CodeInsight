//#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    long long int x;
    cin >> x;
    long long int ans = 1000 * (x / 500) + 5 * ((x % 500) / 5);
    cout << ans << endl;
    return 0;
}