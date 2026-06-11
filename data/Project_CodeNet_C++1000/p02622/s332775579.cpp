#include <iostream>
#include<string>
using namespace std;
int main()
{   int Count=0;
    string S;
    string T;
    cin >> S >> T;
    for(int i=0; i < S.size(); i++){
        if(S[i] != T[i]){
            Count+=1;
        }
    }
    cout<<Count;
    return 0;
}