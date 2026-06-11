#include <iostream>

using namespace std;

int main()
{
    int th, ta, ah, aa;
    cin >> th >> ta >> ah >> aa;
    if (th / aa + (th % aa > 0) < ah / ta + (ah % ta > 0))
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
}