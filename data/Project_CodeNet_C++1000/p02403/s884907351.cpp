#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int num1, num2;
    cin >> num1 >> num2;
    while(num1 != 0 || num2 != 0){
        for(int i = 0; i < num1; ++i){
            for(int j = 0; j < num2; ++j){
                cout << "#";
            }
            cout << endl;
        }
        cout << endl;
        cin >> num1 >> num2;
    }
}