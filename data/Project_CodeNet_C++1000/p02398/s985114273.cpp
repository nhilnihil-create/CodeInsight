#include<iostream>
using namespace std;
int main() {
    int a, b, c;
    int count;
    cin >> a >> b >> c;
    while(a <= b) {
        if (c % a == 0) {
            count ++;
        }
        a++;
    }
    cout << count << endl;
}
