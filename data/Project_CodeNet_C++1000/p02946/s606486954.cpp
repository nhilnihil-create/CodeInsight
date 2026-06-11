#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    
    int k, x;
    cin >> k >> x;
    
    int max = x + (k - 1);
    int min = x - (k - 1);
    
    for(int i = min; i <= max; i ++){
        cout << i << " " ;
    }
}