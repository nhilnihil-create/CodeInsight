#include <iostream>
using namespace std;
int main(void){
    int N, a, i, x;
    cin >> N;
    x = 0;
    for(i = 1; N >= i; i++){
        if(i%2 == 1){
            x = x + 1;
        }
    }
    cout << (double)x/N << endl;
    
    
    
    return 0;
    
    
    
    
    
    
    
    
}
