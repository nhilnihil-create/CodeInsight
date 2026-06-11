#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string alphabet;
    cin >> alphabet;
    if(alphabet[0] >= 'A' && alphabet[0] <= 'Z')
    {
        cout << "A" << endl;
    }
    if(alphabet[0] >= 'a' && alphabet[0] <= 'z')
    {
        cout << "a" << endl;
    }
}