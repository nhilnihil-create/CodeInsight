#include <bits/stdc++.h>
using namespace std;

int	main()
{
    int N, K;
    cin >> N >> K;
    vector<int> H_vec(N);
    for (int i = 0; i < N; ++i)
        cin >> H_vec.at(i);
    sort(H_vec.begin(), H_vec.end());
    int64_t cnt = 0;
    for (int i = 0; i < N - K; ++i)
        cnt += H_vec.at(i);
    cout << cnt << endl;
}
