#include <iostream>
using namespace std;

int main() {
    int testcase = 0;
    int num1, num2;
    int cnt = 0;
    bool jail = false;
    cin >> testcase;
    for (int i = 0; i < testcase; i++) {
        cin >> num1 >> num2;
        if (num1 == num2){
            cnt++;
            if (cnt >= 3){
                jail = true;
            }
        }else{
            cnt = 0;
        }
    }
    if (jail){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
