#include <iostream>
using namespace std;
int main(void){
    
    int N;
    cin >> N;
    
    int one_keta = N % 10;
    
    if(one_keta == 3){
        cout << "bon" << endl;
    }
    else if(one_keta == 0 || one_keta == 1 || one_keta == 6 || one_keta == 8){
        cout << "pon" << endl;
    }
    else{
        cout << "hon" << endl;
    }
    
    
}
