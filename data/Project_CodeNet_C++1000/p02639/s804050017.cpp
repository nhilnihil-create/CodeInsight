#include <iostream>
using namespace std;
int main(void){
    
    for(int i = 1; i <= 5; i++){
        int x;
        cin >> x;
        if(x == 0){
            cout << i << endl;
            break;
        }
    }
}
