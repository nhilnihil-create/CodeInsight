#include<bits/stdc++.h>
using namespace std;
template <typename T> using vec = vector<T>;

int main()
{
    int n;
    cin >> n;
    int left = (100*n + 108 -1) / 108;
    int right = (100*(n+1) + 108 - 1) / 108 - 1;
    if (left == right)
    {
        cout << left << endl;
    }
    else
    {
        cout << ":(" << endl;
    }
}
