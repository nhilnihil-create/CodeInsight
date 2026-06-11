#include<iostream>
using namespace std;
int main()
{
    int A,B;
    cin >> A >> B;
    if(A<=9 && B<=9)
    {
        int result = A*B;
        cout << result << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
    return 0;
 
 
}