#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(void){
    
    int N;
    cin >> N;
    
    while(N != 0){
        if(N % 10 == 7){
            cout << "Yes" << endl;
            return 0;
        }
        N /= 10;
    }
    
    cout << "No" << endl;
}
