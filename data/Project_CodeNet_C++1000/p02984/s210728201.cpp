#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long N;
    cin >> N;
    vector<long long> a(N);
    for (long long i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    long long cnt = 0;
    for (long long i = N-1; i > -1; i--)
    {
        cnt = a[i] - cnt;
    }
    cout << cnt << " ";

    for (long long i = 0; i < N-1; i++)
    {
        cnt = 2 * (a[i] - (cnt / 2));
        cout << cnt << " ";
    }
    cout << endl;
}