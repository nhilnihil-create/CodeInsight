#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int N;
    cin >> N;
    
    int count = 0;
    
    for(int i = 1; i <= N; i ++){
        if(i % 2 == 1){
            count ++;
        }
    }
    cout << (double)count/N << endl;    
}
