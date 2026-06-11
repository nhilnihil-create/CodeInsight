#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n, a, b;
    cin >> n >> a >> b;

    cout << (n /(a+b))*a + min((n%(a+b)),a) << endl;
    return 0;
}