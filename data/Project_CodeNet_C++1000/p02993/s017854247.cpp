#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string S ;
    getline (cin, S);
    if (S[0] != S[1]) {
        if (S[1] != S[2]){
            if (S[2] != S[3]) {
                cout<< "Good";
            }
            else {
                cout<< "Bad";
            }
        }
        else {
            cout<< "Bad";
        }
    }
    else {
        cout<< "Bad";
    }

    return 0;
}
