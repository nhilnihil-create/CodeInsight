#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S;
    cin >> S;

    if(S.size() == 0 || S.size()%2 == 1) {
        cout << "No" << endl;
        return 0;
    }

    bool is_hitachi = true;
    for(int i = 0; i < S.size(); i += 2) {
        if(S[i] == 'h' && S[i+1] == 'i') {
            ;
        } else {
            is_hitachi = false;
        }
    }

    if(is_hitachi) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}