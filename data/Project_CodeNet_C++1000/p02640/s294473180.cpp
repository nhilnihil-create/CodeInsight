#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
long long x,y;
int main() {
    cin >> x >> y;
    if(y >= 2*x && (y-2*x)%2 == 0 && y <= 4*x) cout << "Yes";
    else cout << "No";
    return 0;
}