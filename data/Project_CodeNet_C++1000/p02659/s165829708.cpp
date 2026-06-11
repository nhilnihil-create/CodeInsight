#include<iostream>
using namespace std;

int main() {
    long long a; 
    int b, c;
    scanf("%ld %d.%d", &a, &b, &c);
    long long d = b * 100 + c;

    cout << a * d / 100 << endl;
}