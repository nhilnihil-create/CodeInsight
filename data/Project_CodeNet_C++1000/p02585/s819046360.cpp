#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int N, K;
    cin >> N;
    cin >> K;
    vector<long long int> P(N + 1);
    vector<long long int> C(N + 1);
    long long int i, j;
    for (i = 1; i < N + 1; i++)
    {
        cin >> P[i];
    }
    for (i = 1; i < N + 1; i++)
    {
        cin >> C[i];
    }
    vector<vector<long long int>> score(N + 1, vector<long long int>(N + 1));
    vector<vector<long long int>> move(N + 1, vector<long long int>(N + 1));
    vector<long long int> end(N + 1);
    for (i = 1; i < N + 1; i++)
    {
        score[i][0] = 0;
        move[i][0] = i;
        end[i] = -1;
        for (j = 1; j < N + 1; j++)
        {
            move[i][j] = P[move[i][j - 1]];
            if (move[i][j] == i && end[i] == -1)
            {
                end[i] = j;
            }
            score[i][j] = score[i][j - 1] + C[move[i][j]];
        }
    }
    long long int result = -1000000001;
    long long int ans;
    for (i = 1; i < N + 1; i++)
    {
        if (score[i][end[i]] > 0 && K > end[i])
        {
            ans = max(score[i][end[i]] * (K / end[i]) + *(max_element(score[i].begin(), score[i].begin() + K % end[i] + 1)), score[i][end[i]] * (K / end[i] - 1) + *(max_element(score[i].begin(), score[i].begin() + end[i] + 1)));
            if (ans > result)
            {
                result = ans;
            }
        }
        else if (K > end[i])
        {
            ans = *max_element(score[i].begin() + 1, score[i].begin() + end[i] + 1);
            if (ans > result)
            {
                result = ans;
            }
        }
        else
        {
            ans = *max_element(score[i].begin() + 1, score[i].begin() + K + 1);
            if (ans > result)
            {
                result = ans;
            }
        }
    }
    cout << result << endl;
    return 0;
}