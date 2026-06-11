#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long N, M;
    cin >> N >> M;
    vector<long long> vec(N);
    for (long long i = 0; i< N; i++)
    {
        cin >> vec[i];
    }
    sort(vec.begin(), vec.end());

    for (long long i = 0; i < M; i++)
    {
        vec[N-1] = vec[N-1] / 2;

        long long minnum = -1;
        long long maxnum = N-1;
        while(1)
        {
            if(maxnum - minnum <= 1)
            {
                vec.insert(vec.begin() + maxnum, vec[N-1]);
                vec.pop_back();
                break;
            }
            if(vec[N-1] > vec[(minnum + maxnum) / 2])
            {
                minnum = (minnum + maxnum) / 2;
            }
            else
            {
                maxnum = (minnum + maxnum) / 2;
            }
        }
    }

    long long ans = 0;
    for (long long i = 0; i < N; i++)
    {
        ans += vec[i];
    }
    cout << ans << endl;
}