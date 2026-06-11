#include <iostream>
#include <cstring>
using namespace std;
char S[15];
int main()
{
    cin >> S;
    if(strlen(S) % 2 != 0){
        cout << "No\n";
        return 0;
    }
    for(int i = 0; i < strlen(S); i += 2)
    if(!(S[i] == 'h' && S[i + 1] == 'i')){
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";
    return 0;
}
