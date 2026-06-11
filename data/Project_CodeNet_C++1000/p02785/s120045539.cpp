#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K, doko;
    long long ans = 0;
    cin >> N >> K;
    vector<int> H(N),hissatsu(K);
    for(int i=0;i<N;i++)
    {
        cin >> H.at(i);
    }
    sort(H.begin(), H.end());
    for(int i=0;i<N-K;i++)
    {
        ans += H.at(i);
    }
    cout << ans << endl;
}
