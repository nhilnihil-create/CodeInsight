#include<iostream>
#include<cctype>
using namespace std;

char ch;

void read() {
    cin >> ch;
}


void work() {
    cout << (isupper(ch) ? 'A' : 'a') << endl;
}


int main() {
    read();
    work();
    return 0;
}
