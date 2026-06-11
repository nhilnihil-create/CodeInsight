#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    string s(b, '0' + a);
    string t(a, '0' + b);
    cout << min(s, t) << endl;
    return 0;
}
