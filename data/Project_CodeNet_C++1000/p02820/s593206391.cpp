#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000;//1e18
const double EPS = 1e-10;

int main(void)
{
    int N, K;
    cin >> N >> K;

    // 得点
    int R, S, P;
    cin >> R >> S >> P;

    string T;
    cin >> T;

    vector<char> log(N);
    vector<int> ans(N, 0);

    int i;
    for (i = 0; i < K; i++)
    {
        if (T[i] == 'r')
        {
            ans[i] = P;
            log[i] = 'p';
        }
        else if (T[i] == 's')
        {
            ans[i] = R;
            log[i] = 'r';
        }
        else
        {
            ans[i] = S;
            log[i] = 's';
        }
    }
    // K ~ MAX - K
    for (; i < T.size() - K; i++)
    {
        if (T[i] == 'r')
        {
            if (log[i - K] != 'p')
            {
                ans[i] = P;
                log[i] = 'p';
            }
            else
            {
                log[i] = T[i + K];
            }
        }
        else if (T[i] == 's')
        {
            if (log[i - K] != 'r')
            {
                ans[i] = R;
                log[i] = 'r';
            }
            else
            {
                log[i] = T[i + K];
            }
        }
        else
        {
            if (log[i - K] != 's')
            {
                ans[i] = S;
                log[i] = 's';
            }
            else
            {
                log[i] = T[i + K];
            }
        }
    }
    for (; i < T.size(); i++)
    {
        if (T[i] == 'r')
        {
            if (log[i - K] != 'p')
            {
                ans[i] = P;
            }
        }
        else if (T[i] == 's')
        {
            if (log[i - K] != 'r')
            {
                ans[i] = R;
            }
        }
        else
        {
            if (log[i - K] != 's')
            {
                ans[i] = S;
            }
        }
    }
    ll all = 0;
    for (int i = 0; i < N; i++)
    {
        // printf("%d ", ans[i]);
        all += ans[i];
    }
    // printf("\n");
    // for (int i = 0; i < N; i++)
    // {
    //     printf("%c ", log[i]);
    // }
    cout << all << endl;
    return (0);
}