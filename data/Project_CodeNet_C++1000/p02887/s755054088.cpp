#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main(void){
    string str;
    char c, prev;
    int N;
    cin >> N;
    cin >> c;
    str += c; prev = c;
    for (int i = 1; i < N; i++) {
        cin >> c;
        if (c != prev) {
            prev = c;
            str += c;
        }
    }
    cout << str.size() << endl;
    return 0;
}
