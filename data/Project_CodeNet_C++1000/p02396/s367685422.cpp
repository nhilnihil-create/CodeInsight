#include <iostream>
using namespace std;

main()
{
    int A[10000], i = 0;
    while (cin >> A[i])
        {
            if (A[i] == 0)
                break;
            else
            cout << "Case " << i+1 << ": " << A[i] << endl;
            i++;
        }
    return 0;
}