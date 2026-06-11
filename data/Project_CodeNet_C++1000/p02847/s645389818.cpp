#include <iostream>
#include<map>
using namespace std;
#define fin(ans) cout << (ans) << '\n'
int main()
{
    string S;
    cin >> S;
    if(S[0] == 'S'){
        if(S[1] == 'U') fin(7);
        else fin(1);
    }else if(S[0] == 'M') fin(6);
    else if(S[0] == 'T'){
        if(S[1] == 'U') fin(5);
        else fin(3);
    }else if(S[0] == 'W') fin(4);
    else fin(2);
    return 0;
}