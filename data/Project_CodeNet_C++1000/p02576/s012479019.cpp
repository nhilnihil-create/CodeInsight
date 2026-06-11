#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    int n, x, t; cin >> n >> x >> t;
    cout << int(ceil(n * 1.0 / x) * t) << endl;
}