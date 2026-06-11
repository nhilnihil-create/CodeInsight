#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    int* A = new int[N];
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        sum += A[i];
    }

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        double pomer = (double)A[i] / (double)sum;
        if ( pomer >= 1.0 / (4.0 * (double)M))
            count++;
    }

    if (count>=M)
        cout << "Yes";
    else
        cout << "No";


    return 0;
}