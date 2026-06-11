#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    long long a;
    long long v;
    cin >> a >> v;
    long long b;
    long long w;
    cin >> b >> w;
    long long t;
    cin >> t;
    long long d = abs(a - b);
    long long d2 = (v - w) * t;
    if(d <= d2){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}