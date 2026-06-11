#include <iostream>
#include <string>
using namespace std;

int main(void){
    string str;
    cin >> str;
    int size = int(str.size());
    (str.substr(0, size/2) == str.substr(size/2+1)) ? cout << "Yes" << endl : cout << "No" << endl;
    return 0;
}
