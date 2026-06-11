#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(N);

    for (auto &x : A)
    {
        cin >> x;
    }
    int compa = (accumulate(A.begin(), A.end(), 0) + (4 * M)-1) / (4 * M);

    int ans = 0;
    for (auto &x : A)
    {
        if (compa <= x)
        {
            ans++;
        }
    }
    if (ans>=M)
    {
        cout << "Yes";
    }else
    {
        cout << "No";
    }
    cout << endl;
}