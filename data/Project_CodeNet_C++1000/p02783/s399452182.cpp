#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int N,i,j,k;
    bool flag;
    flag=false;
    cin >> N>>i;

    
    if (N%i==0){
        cout << N/i <<endl;
        
    }
    else{
        cout << N/i+1 <<endl;
    }
    return 0;
    
}
