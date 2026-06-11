#include <iostream>
#include <string>
using namespace std;

int main (void){
    int p, q, r;
    cin >> p >> q >> r;
    if(p + q < r + q){
        if(p + q < p + r){
            cout << p + q << endl;
        }else{
            if(p + r < r + q){
                cout << p + r << endl;
            }else{
                cout << r + q << endl;
            }
        }
    }else if(r + q < p + r){
        if(r + q < p + q){
            cout << r + q << endl;
        }else{
            if(p + r < p + q){
                cout << p + r << endl;
            }else{
                cout << p + q << endl;
            }
        }
    }else{
        if(p + r < p + q){
            cout << p + r << endl;
        }else{
            if(p + q < r + q){
                cout << p + q << endl;
            }else{
                cout << r + q << endl;
            }
        }
    }
    return 0;
}

