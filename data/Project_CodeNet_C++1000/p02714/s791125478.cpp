#include <algorithm>
#include <deque>
#include <iostream>
#include <numeric>
using namespace std;

int main()
{

    int N;
    cin >> N;
    string S;
    cin >> S;
    long long  ans = 0;
    deque<long> R(N), G(N), B(N);
    for (int i = 0; i < N; i++)
    {
        if (S[i] == 'R')
        {
            R[i]++;
        }
        else if (S[i] == 'G')
        {
            G[i]++;
        }
        else
        {
            B[i]++;
        }
    }

    for (int i = N - 1; i > 0; i--)
    {
        R[i - 1] = R[i] + R[i - 1];
        G[i - 1] = G[i] + G[i - 1];
        B[i - 1] = B[i] + B[i - 1];
    }

    for (int i = 0; i < N ; i++)
    {

        for (int j = i + 1; j < N ; j++)
        {
            if (S[j] != S[i])
            {
                if (S[i] == 'R' && S[j] == 'G' || S[i] == 'G' && S[j] == 'R')
                {
                    ans += B[j];
                    if (S[j + (j - i)] == 'B')
                    {
                        ans--;
                    }
                }
                else if (S[i] == 'R' && S[j] == 'B' || S[i] == 'B' && S[j] == 'R')
                {
                    ans += G[j];
                    if (S[j + (j - i)] == 'G'){
                        ans--;
                    }
                }
                else
                {
                    ans += R[j];
                    if (S[j + (j - i)] == 'R'){ 
                        ans--;
                    }
                }
            }
        }
    }

    cout << ans << endl;
}