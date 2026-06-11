#include <iostream>
using namespace std;

int main ()
{
    string S;
    cin >> S;
    bool palindrome = true;

    if (S.size()%2 != 0)
    {
        int i = 0, j = S.size()-1;
        while (i!=j)
        {
            palindrome = palindrome && (S[i] == S[j]);
            i++;
            j--;
        }

        i = 0; j++;
        while (j != S.size())
        {
            palindrome = palindrome && (S[i] == S[j]);
            i++;
            j++;
        }
    }
    else
    {
        palindrome = false;
    }

    if(palindrome)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}