#include <iostream>
#include <algorithm>
#include <math.h> 
#include <string>
#include <iomanip>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <bitset>
using namespace std;
int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x, y;
    if(a%d == 0) x = a/d;
    else x = a/d + 1;

    if(c%b == 0) y = c/b;
    else y = c/b + 1;

    if(y <= x) cout << "Yes" << endl;
    else cout << "No" << endl;
    //cout << x << " " << y << endl;
}
