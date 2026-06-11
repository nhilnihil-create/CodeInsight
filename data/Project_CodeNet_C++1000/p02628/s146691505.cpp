#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n, k, * N, total = 0;
    cin >> n >> k;
    N = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> N[i];
    }
    sort(N, N + n);
    for (int i = 0; i < k; i++)
    {
        total += N[i];
    }
    cout << total << endl;
    delete[]N; 
}