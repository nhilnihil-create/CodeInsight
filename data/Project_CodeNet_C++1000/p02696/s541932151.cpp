#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    long long int a,b,n;
    cin >>a >>b >>n;
    if(b <= n) {
        cout << floor(a*(b-1)/b) -(a*floor((b-1)/b)) << endl;
        return 0;
    } else {
        cout << floor(a*n/b) -(a*floor(n/b)) << endl;
        return 0;
    }
}