#include <iostream>
#include <algorithm>

using namespace std;

void trace(int* A, int n)
{
    cout << A[0];
    for(int i=1; i < n; i++)
    {
        cout << " " << A[i];
    }
    cout << endl;

    return;
}

int insertionSort(int A[], int n, int g)
{
    int cnt = 0;

    for(int i = g; i < n; i++)
    {
        int v = A[i];
        int j = i - g;

        while(j >= 0 && A[j] > v)
        {
            A[j+g] = A[j];
            j -= g;
            cnt++;
        }
        A[j+g] = v;
    }

    return cnt;
}

int shellSort(int A[], int n)
{
    int cnt = 0;
    int m = 1;
    int G[100];

    G[0] = 1;
    for(int i = 1; i < 100; i++)
    {
        if(3 * G[i-1] + 1 > n)
            break;
        G[i] = 3 * G[i-1] + 1;
        m++;
    }

    cout << m << endl;
    cout << G[m-1];
    for(int i = m-2; i >= 0; i--)
        cout << " " << G[i];
    cout << endl;

    for(int i = m-1; i >= 0; i--)
    {
        cnt += insertionSort(A, n, G[i]);
    }

    return cnt;
}

int main(void)
{
    int n;
    int A[1000000];

    cin >> n;
    for(int i=0; i < n; i++) cin >> A[i];

    cout << shellSort(A, n) << endl;
    for(int i = 0; i < n; i++)
        cout << A[i] << endl;

    return 0;
}