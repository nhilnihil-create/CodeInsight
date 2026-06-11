#include <iostream>
using namespace std;
int main()
{
    char S[7];
    cin >> S;
    if(S[2]== S[3]) {
        if(S[4]==S[5]){
       cout << "Yes" << endl;
        }
        else cout << "No" << endl;
     }
    else cout << "No" << endl;
    return 0;
}