#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string n; cin >> n;
    bool flag = false;
    for (char p:n)
    {
        if (p == '7')
        {
            flag = true;
            break;
        }
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}