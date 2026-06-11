#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int N, A;
    string b;
    cin >> N;
    
    for ( int i = 0; i < N; ++i)
    {
        cin >> A;
        if ( A % 2 == 0 )
        {
            if(A%3 != 0 && A%5 !=0)
            {
                b = "DENIED";
                break;
            }
        }
    }
    
    if(b == "DENIED")
    {
        cout << b << endl;
    }
    else
    {
        cout << "APPROVED" << endl;
    }
}
