#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int A, B;
    cin >> A >> B;
    
    if(A/(B*2) == 0)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << A - (B * 2) << endl;
    }
}
