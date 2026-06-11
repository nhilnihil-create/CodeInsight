#include <iostream>

using namespace std;

int main(void)
{
    string S;

    cin >> S;

    if (S[S.size() - 1] == 's') {
        cout << S << "es" << endl;
    } else {
        cout << S << "s" << endl;
    }
    
    return 0;
}