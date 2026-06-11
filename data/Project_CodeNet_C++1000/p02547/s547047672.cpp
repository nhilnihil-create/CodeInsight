#include <iostream>

using namespace std;

int main()
{
    int a, b;
    int n, m = 0;
    cin >> n;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if(a == b) m++;
        else m = 0;
        if (m >= 3) flag = true;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}