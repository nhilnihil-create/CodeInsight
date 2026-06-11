#include <iostream>

#define OK 0;
#define START 0;
using namespace std;


int main(void) {
    unsigned int a = START;
    unsigned int b = START;

    //scanf
    cin >> a >> b;

    if (a < b) {
        cout << "a < b" << endl;
    }
    else if (a > b) {
        cout << "a > b" << endl;

    }
    else {
        cout << "a == b" << endl;
    }

    return OK;
}