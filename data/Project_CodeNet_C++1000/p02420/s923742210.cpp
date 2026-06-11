#include <iostream>
using namespace std;

string shuffle(string str, int n)
{
    string leftString = str.substr(0, n);
    string rightString = str.substr(n, str.size());

    return rightString + leftString;
}

int main()
{
    string str;
    int m, n;

    while (true) {
        cin >> str;

        if (!str.compare("-")) {
            return 0;
        }

        cin >> m;

        for (int i = 0; i < m; i++) {
            cin >> n;
            str = shuffle(str, n);
        }

        cout << str << endl;
    }
}