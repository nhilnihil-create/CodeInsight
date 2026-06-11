#include <iostream>
#include <vector>
 
using namespace std;
int cnt = 0;
 
void insertionSort(vector<int>& A, int g)
{
    for (int i = g; i < A.size(); ++i)
    {
        if (A[i - g] > A[i])
        {
            int v = A[i];
            int j = i - g;
            while (j >= 0 && A[j] > v)
            {
                A[j + g] = A[j];
                j -= g;
                ++cnt;
            }
            A[j + g] = v;
        }
    }
}
 
void solve()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }
    cnt = 0;
    vector<int> G;
    int h = 1;
    while (N >= h)
    {
        G.push_back(h);
        h = 3 * h + 1;
    }
    for (int i = G.size() - 1; i >= 0; --i)
    {
        insertionSort(A, G[i]);
    }
    cout << G.size() << endl;
    for (int i = G.size() - 1; i > 0; --i)
    {
        cout << G[i] << " ";
    }
    cout << G[0] << endl;
    cout << cnt << endl;
    for (int i = 0; i < A.size(); ++i)
    {
        cout << A[i] << endl;
    }
}
 
int main()
{
    solve();
    return(0);
}
