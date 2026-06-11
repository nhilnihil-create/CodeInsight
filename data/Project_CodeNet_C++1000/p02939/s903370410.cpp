#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    string S;
    cin >> S;
    int cnt = (int)S.length();
    for (int i = 0; i < (int)S.length(); i++)
    {
        if (S[i - 1] == S[i])
        {
            cnt--;
            i += 2;
        }

    }
    
    cout << cnt << endl;
    
    return 0;
}