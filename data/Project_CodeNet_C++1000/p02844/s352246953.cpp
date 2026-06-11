#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<vector<int>> pre(N);
    vector<int> cnt(10, 0);
    for(int i=0; i<N; i++)
    {
        pre[i] = cnt;
        cnt[(S[i] - '0')]++;
    }

    vector<vector<int>> post(N);
    cnt.assign(10, 0);
    for(int i=N-1; i>=0; i--)
    {
        post[i] = cnt;
        cnt[(S[i] - '0')]++;
    }

    vector<vector<vector<int>>> mp(10, vector<vector<int>>(10, vector<int>(10, 0)));
    int ans = 0;
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(pre[i][j] == 0) continue;
            for(int k=0; k<10; k++)
            {
                if(post[i][k] == 0) continue;
                if(mp[j][(S[i] - '0')][k] == 0)
                {
                    mp[j][(S[i] - '0')][k]++;
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
