#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

using std::string;
using std::unordered_set;

int main()
{
    string a;
    cin >> a;

    unordered_set<char> chars;

    for (int i = 0; i < a.length(); i++)
    {
        chars.insert(a[i]);
    }

    if (chars.size() == 2)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}