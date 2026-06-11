#include <iostream>
#include <string>
using namespace std;
int main()
{
    string S,T;
    getline(cin,S);
    getline(cin,T);
    int counter=0;
    for (int i=0;i<S.length();i++)
    {
        if (S[i]!=T[i])
            counter++;
    }
    cout<<counter;
    return 0;
}