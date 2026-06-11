#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<char> vec(N+2);
    vec[0] = 'X';
    vec[N+1] = 'X';
    for (long long i = 1; i < N+1; i++)
    {
        vec[i] = S[i-1];
    }

    int flg = 0;
    long long cnt = 0;
    for (long long i =2; i < N+1; i++)
    {
        if (vec[i] == vec[1])
        {
            if (flg == 1)
            {
                if (cnt == K)
                {
                    break;
                }
                flg = 0;
            }
        }
        else
        {
            vec[i] = vec[1];
            if (flg == 0)
            {
                cnt++;
                flg = 1;
            }
        }
    }

    long long ans = 0;
    for (long long i = 1; i < N+1; i++)
    {
        if (vec[i] == 'L')
        {
            if (vec[i-1] == 'L')
            {
                ans++;
            }
        }
        else
        {
            if (vec[i+1] == 'R')
            {
                ans++;
            }
        }
    }
    cout << ans <<endl;
}