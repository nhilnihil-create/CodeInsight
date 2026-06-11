#include <iostream>
#include <string>
using namespace std;
int main(void){
    // Your code here!
    string n;
    cin >> n;
    int sum = 0;
    for (auto i : n) {
        sum += (int)i - 48;
        sum %= 9;
    }
    cout << ((!(sum % 9))?"Yes":"No") << endl;
}