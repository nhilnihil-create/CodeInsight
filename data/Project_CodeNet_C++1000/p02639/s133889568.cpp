#include <iostream>
using namespace std;
int main(void){
    
    int N[6];
    for(int i = 1; i < 6; i++){
        cin >> N[i];
    }
    
    for(int i = 1; i < 6; i++){
        if(N[i] == 0){
            cout << i << endl;
            break;
        }
    }
    
    
}
