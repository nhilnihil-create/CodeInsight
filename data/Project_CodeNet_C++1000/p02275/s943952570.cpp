#include <iostream>
#define SIZE 2000000 //確保する配列の要素数
using namespace std;
const int num = 10000; //入力される最大値

void CountingSort(int *A, int *B, int k)
{
    int C[num] = {};

    for (int i = 0; i < k; i++)
    {
        C[A[i]]++;
    }

    for (int i = 1; i < num; i++)
    {
        C[i] = C[i] + C[i - 1];
    }

    for (int j = k - 1; j >= 0; j--)
    {
        B[C[A[j]] - 1] = A[j];
        C[A[j]]--;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A[SIZE];
    int B[SIZE];
    int k; //使う配列の要素数

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> A[i];
    }

    CountingSort(A, B, k);

    int i;
    for (i = 0; i < k - 1; i++)
    {
        cout << B[i] << ' ';
    }
    cout << B[i] << endl;
}
