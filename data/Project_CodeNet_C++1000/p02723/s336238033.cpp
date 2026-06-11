#include <iostream>
using namespace std;

int main() {
    string stra;
    cin >> stra;
    if((stra[2]==stra[3])&&(stra[4]==stra[5])){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}