#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <unordered_map>
#include <iomanip>
using namespace std;

long long gcd(long long a, long long b){
    if (a < b) return gcd(b, a);
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main(){
    long long a, b;
    cin >> a >> b;
    cout << a * b / gcd(a, b) << endl;
    return 0;
}