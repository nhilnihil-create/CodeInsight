#include <iostream>
using namespace std;
int main(void){
    int A,B,C,K;
    cin >> A >> B >> C >> K;
    
    int i = 0;
    while(!(A < B && B < C)){
        if(A >= B){
            B *= 2;
        }
        else{
            C *= 2;
        }
        i++;
    }
    if(i <= K){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    
}
