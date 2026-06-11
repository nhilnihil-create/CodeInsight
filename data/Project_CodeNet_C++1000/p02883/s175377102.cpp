#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
using ll = long long;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N), F(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> F[i];
    sort(A.begin(), A.end());
    sort(F.begin(), F.end(), greater<ll>());
    ll highest = 0;
    for (int i = 0; i < N ; i++)
        highest = max(highest, A[i] * F[i]);
    ll lowest = -1;
    while (highest - lowest > 1)
    {
        ll border_score = (highest + lowest) / 2, train_cnt = 0;
        for (int i = 0; i < N; i++)
            train_cnt += max(A[i] - (border_score / F[i]), 0ll);
        if(train_cnt <= K)
            highest = border_score;
        else
            lowest = border_score;
    }
    cout << highest << endl;
}