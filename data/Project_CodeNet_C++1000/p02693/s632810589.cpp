#include<iostream>
#include<string>

using namespace std;

int main(void) {
    int k, a, b;
    cin >> k >> a >> b;

    int n = 1;
    while(n*k <= b) {
        n++;
    }

    cout << ((n-1)*k >= a ? "OK" : "NG") << endl;

    return 0;
}
