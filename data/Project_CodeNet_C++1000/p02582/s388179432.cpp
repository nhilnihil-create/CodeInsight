#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    string S;
    cin>>S;

    bool a =S[0] =='R';
    bool b =S[1] =='R';
    bool c =S[2] =='R';
    if(a && b && c){
        cout<<"3";
    }
    else if((a && b) || (b && c)){
        cout<<"2";
    }
    else if(a || b||c){
        cout<<"1";
    }
    else{
        cout<<"0";
    }

    return 0;
}