#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    char letter;
    cin>>letter;
    if(isupper(letter)){
        cout<<'A';
    }
    else{
        cout<<'a';
    }

    return 0;
}