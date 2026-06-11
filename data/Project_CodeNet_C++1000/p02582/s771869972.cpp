#include<iostream>
using namespace std;


string s;

void read() {
    cin >> s;
}


void work() {
    for (int i = 3; i >= 0; --i) {
        if (s.find(string(i, 'R')) != string::npos) {
                cout << i << endl;
                return;
            }
    }
}


int main() {
    read();
    work();
    return 0;
}
