#include <iostream>
using namespace std;
int main(void){
    int A,B,C;
    cin >> A >> B >> C;
    if(A-B >=C){
        cout << "0" << endl;
    }
    else if(A-B <C){
        cout << C-(A-B) << endl;
    }
    return 0;
}