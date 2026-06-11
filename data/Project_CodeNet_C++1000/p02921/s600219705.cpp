#include <iostream>

using namespace std;

int main()
{
    int m , i ;
    string T , S ;
    m = 0 ;
    cin >> S >> T ;
    for(i=0; i <= 2 ; i++)
    {
        if(S[i] == T[i])
        {
            m = m + 1 ;
        }
    }


    cout << m << endl;
    return 0;
}
