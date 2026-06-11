#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    map<int, long> B{};
    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i);
        B[A.at(i)]++;
    }

    long sum = 0;
    for (pair<int, long> p : B)
    {
        sum += p.second * (p.second - 1) / 2;
    }

    for (int i = 0; i < N; i++)
    {
        cout << sum - B[A.at(i)] + 1 << endl;
    }

    return 0;
}