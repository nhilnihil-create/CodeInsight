#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
using ll = long long;

int gcd(int a, int b){
    if(b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int x;
    cin >> x;
    int i = gcd(x, 360);
    cout << 360 / i << endl;
    return 0;
}