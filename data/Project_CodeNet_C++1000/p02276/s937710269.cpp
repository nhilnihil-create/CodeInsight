#include <iostream>
using namespace std;
#define MAX 100000

int Partition(int A[], int p, int r)
{
    int x = A[r];
    int i = p - 1;
    int temp;
    for (int j = p; j < r; j++)
    {
        if (x >= A[j])
        {
            i++;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    temp = A[i + 1];
    A[i+1] = A[r];
    A[r] = temp;
    return i + 1;
}

int main()
{
    int A[MAX];
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];

   int q=Partition(A,0,n-1);

    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << " ";
        if (i==q)
        {
            cout<<"["<<A[i]<<"]";
            continue;
        }
        cout << A[i];
    }
    cout << endl;

    return 0;
}
