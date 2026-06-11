#include <iostream>

using namespace std;

int main()
{
    string s;
    char a1 , a2;
    cin >> s;
    a1 = s[0];
    if (s[1] == a1){
        if (s[2] == a1){
            cout << "No";
            return 0;
        }else if (s[3] == a1){
            cout << "No";
            return 0;
        }else if (s[2] == s[3]){
            cout << "Yes";
            return 0;
        }else{
            cout << "No";
            return 0;
        }
    }else{
        a2 = s[1];
        if (s[2] == a1){
            if (s[3] == a2){
                cout << "Yes";
                return 0;
            }else{
                cout << "No";
                return 0;
            }
        }else if (s[2] == a2){
            if (s[3] == a1){
                cout << "Yes";
                return 0;
            }else{
                cout << "No";
                return 0;
            }
        }else{
            cout << "No";
            return 0;
        }
    }
    return 0;
}
