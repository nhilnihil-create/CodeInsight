#include <iostream>
using namespace std;
int main()
{
    int A, B, C, D, i = 0;
    cin >> A >> B >> C >> D;
    while (A > 0 && C > 0)
    {
        if (i % 2 == 0)
        {
            C -= B;
            i++;
        }
        else
        {
            A -= D;
            i++;
        }
    }
    if (A <= 0)
        cout << "No";
    else
        cout << "Yes";
    return 0;
}
