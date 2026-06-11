#include <iostream>
#include <cstring>
using namespace std;

int main()
{

    int c=0 ;
    string S ,T ;
    cin>> S >> T ;
    for(int i=0 ; i< S.length() ; i++){
        if(S[i]!=T[i])
            c+=1 ;
    }
    cout<< c ;
    return 0;
}
