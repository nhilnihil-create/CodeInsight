#include <iostream>
using namespace std;
int main()
{
    int N, A[100];
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    int count1 = 0, count2 = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] % 2 == 0)
        {
            count1++;
            if (A[i] % 3 == 0 || A[i] % 5 == 0)
            {
                count2++;
            }
        }
    }
    if (count1 == count2)
    {
        cout << "APPROVED";
    }
    else
    {
        cout << "DENIED";
    }
    return 0;
}