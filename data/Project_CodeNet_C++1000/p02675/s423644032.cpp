#include<iostream>
using namespace std;

int main(void) {
    string N; cin >> N;
    char N1 = N.substr(N.size() - 1).c_str()[0];
    if (N1 == '2' || N1 == '4' || N1 == '5' || N1 == '7' || N1 == '9') {
        cout << "hon" << endl;
    } else if (N1 == '0' || N1 == '1' || N1 == '6' || N1 == '8') {
        cout << "pon" << endl;
    } else {
        cout << "bon" << endl;
    }
}
