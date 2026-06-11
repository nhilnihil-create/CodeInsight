#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    char a, b, c, d;
    int aa, bb;
    aa = bb = 0;
    cin >> a;
    
    for(int i = 0; i < 3; ++i){
        cin >> b;
        if(b == a){
            ++aa;
        }
        else if(b == c){
            ++bb;
        }
        else{
            c = b;
        }
    }    
    
    if(aa == 1 && bb == 1){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
