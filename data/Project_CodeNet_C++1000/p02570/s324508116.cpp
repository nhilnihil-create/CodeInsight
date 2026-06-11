#include <iostream>
using namespace std;

int main(){
    int D, T, S;
    cin >> D >> T >> S;
    if(D <= T*S){
        cout << "Yes" << endl;
    }else if(D > T*S){
        cout << "No" << endl;
    }
    return 0;
}