#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
int main()
{
    int n;
    cin >> n;
    vector<vector<int> > m_nd(n, vector<int>(1, -1));
    int depth[n] = {};
    char m_type[n][15];
    rep(i, n)
    {
        int tmpid, tmpdegree;
        cin >> tmpid >> tmpdegree;
        rep(i, tmpdegree)
        {
            int tmp;
            cin >> tmp;
            m_nd[tmp][0] = tmpid;
            depth[tmp] = depth[tmpid] + 1;
            m_nd[tmpid].push_back(tmp);
        }
    }
    rep(i, n)
    {
        if (m_nd[i][0] != -1 && depth[i] - depth[m_nd[i][0]] != 1)
            depth[i] = depth[m_nd[i][0]] + 1;
    }
    rep(i, n)
    {
        if (m_nd[i][0] == -1)
        {
            strcpy(m_type[i], "root");
        }
        else if (m_nd[i].size() <= 1)
        {
            strcpy(m_type[i], "leaf");
        }
        else
        {
            strcpy(m_type[i], "internal node");
        }
    }
    rep(i, n)
    {
        printf("node %d: parent = %d, depth = %d, %s, [", i, m_nd[i][0], depth[i], m_type[i]);
        for (int j = 1; j < m_nd[i].size(); ++j)
        {
            printf("%d", m_nd[i][j]);
            if (j < m_nd[i].size() - 1)
                printf(", ");
        }
        printf("]\n");
    }
}
