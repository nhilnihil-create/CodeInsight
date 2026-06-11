#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N, K, S;
    cin >> N >> K >> S;
    for (int i = 0; i < K; i++)
        cout << S << " ";
    S = (S + 1) % 1000000000;
    for (int i = 0; i < N - K; i++)
        cout << S << " ";
}