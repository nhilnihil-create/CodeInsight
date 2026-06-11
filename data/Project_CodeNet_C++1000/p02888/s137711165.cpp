#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N;
    cin >> N;
    vector<int> L(N);
    vector<int> lenMap(1e3);
    for (int i = 0; i < N; i++)
    {
        cin >> L[i];
        
    }

    sort(L.begin(), L.end());
    ll cnt = 0;

    for(int i = 0; i < N-2; i++){
        for(int j = i+1; j < N-1; j++){
            int lb = lower_bound(L.begin(), L.end(), L[i] + L[j]) - L.begin();
            cnt += lb - j - 1;
        }
    }

    cout << cnt<< endl;

    return 0;
}
