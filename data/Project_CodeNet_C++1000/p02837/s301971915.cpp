#include <bits/stdc++.h>
using namespace std;

int flag_num(int N)
{
    int flag_num = 0;
    for (int i=0; i<=log2(N); i++)
    {
        if (N & (1<<i)) flag_num++;
    }
    return flag_num;
}

int check(int who, int fact)
{
    if (fact & (1<<who)) return 1;
    else return 0;
}

int main()
{
    // 入力受け取り
    int N;
    cin >> N;
    vector<vector<int>> statements(N, vector<int>(N, -1));
    for (int i=0; i<N; i++)
    {
        int A;
        cin >> A;
        statements[i].resize(A);
        for (int j=0; j<A; j++)
        {
            int x, y;
            cin >> x >> y;
            statements[i][x-1] = y;
        }
    }
    
    // 正直者の組み合わせについて全探索．
    int honest_maxnum = 0;
    for (int i=0; i<(1<<N); i++)
    {
        int honest_num = flag_num(i);
        bool possible = true;
        for (int j=0; j<N; j++)
        {
            if (check(j, i))
            {
                for (int k=0; k<N; k++)
                {
                    if (statements[j][k]!=-1) possible = (statements[j][k]==check(k, i));
                    if (!possible) break;
                }
            }
            if (!possible) break;
        }
        if (possible)
        {
            honest_maxnum = max(honest_maxnum, honest_num);
        }
    }
    cout << honest_maxnum << endl;

}