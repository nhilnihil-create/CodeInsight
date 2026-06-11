#include <iostream>
using namespace std;

int main() {
    string input;
    cin >> input;
    int len = input.length();
    if (input[len-1] == 's'){
        cout << input + "es" << endl;
    }else{
        cout << input + "s" << endl;
    }
    return 0;
}
