#include <iostream>
#include <string>
using namespace std;
int main()
{
    char s;
    string letters = "abcdefghijklmnopqrstuvwxyz";
    string res = "";
    cin >> s;
    for(int i = 0; i < letters.length(); i++) {
        if(s == letters[i])
            res+=letters[i+1];
    }
    cout << res << endl;
}