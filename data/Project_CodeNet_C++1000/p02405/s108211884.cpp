#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int num1, num2;
    bool check = true;
    cin >> num1 >> num2;
    while(num1 != 0 || num2 != 0){
        for(int i = 0; i < num1; ++i){
            if(i % 2 == 0){
                check = true;
            }
            else{
                check = false;
            }
            for(int j = 0; j < num2; ++j){
                if(check == true){
                    cout << "#";
                    check = false;
                }
                else{
                    cout << ".";
                    check = true;
                }
            }
            cout << endl;
        }
        cout << endl;
        cin >> num1 >> num2;
    }
}