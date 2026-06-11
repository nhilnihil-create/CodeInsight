#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N, K;
    cin >> N >> K;
    vector<int> p(N);

    for (int i = 0; i < N; i++)
    {
        cin >> p[i];
    }

    ll maxval = 0;
    ll sum = 0;
    for(int i = 0; i < K; i++){
        sum += 1 + p[i];
    }
    maxval = sum;

    for(int i = 1; i < N - K + 1; i++){
        sum = sum - p[i-1] + p[i+K-1];
        if(sum > maxval) maxval = sum;
    }

    double E = maxval * 0.5;

    cout << std::fixed << std::setprecision(10) << E << endl;
    return 0;
}
