#include<iostream>
using namespace std;


int a;

void read() {
    cin >> a;
}


void work() {
    cout << a * (1 + a * (1 + a)) << endl;
}


int main() {
    read();
    work();
    return 0;
}
