#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K, Max, Min, Dif;
    cin >> N >> K;
    Max = (N/K) + (N%K);
    Min = (N/K);
    Dif = Max - Min;
    cout << Dif << endl;
    return 0;
}