#include<bits/stdc++.h>
#include <math.h>
using namespace std;

int x,y,z;

int main() {
    cin >> x >> y >> z;
    int res = x / y;
    if(x % y != 0) {
        res++;
    }
    cout << z * res << endl;
}


