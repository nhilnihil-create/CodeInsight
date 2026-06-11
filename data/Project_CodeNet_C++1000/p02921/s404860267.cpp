#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S, T;
    cin >> S;
    cin >> T;
    int count = 0;
    for(int i = 0; i < 3; i++) {
        if(S[i] == T[i]) {
            count += 1;
        }
    }
    cout << count << endl;
    return 0;
}