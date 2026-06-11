#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
    string s;
    cin>>s;
    bool isgood = true;
    if(s[0] == s[1]){
        isgood = false;
    }
    if(s[1] == s[2]){
        isgood = false;
    }
    if(s[2] == s[3]){
        isgood = false;
    }
    
    if(isgood ){
        cout<<"Good";
    }
    else{
        cout<<"Bad";
    }

    return 0;
}