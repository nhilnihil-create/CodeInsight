#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    string n;
    int a;
    cin >> n;
    a=n.find("7");
    if (a!=-1){
        cout << "Yes";
    }
    else {
        cout << "No";
    }
}
