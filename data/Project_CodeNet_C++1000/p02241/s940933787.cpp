/*
 * Problem Description: Graph II - Minimum Spanning Tree
 * Category: Graph
 * Author: Khan
 * Date: 22th October, 2017
 */

#include <iostream>

using namespace std;

static const int MAX = 1000;
static const int INF = (1 << 21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n, M[MAX][MAX];

int prim()
{
    int u, minv;
    int d[MAX], p[MAX], color[MAX];

    for (int i = 0; i < n; ++i)
    {
        d[i] = INF;
        p[i] = -1;
        color[i] = WHITE;
    }

    d[0] = 0;

    while(true)
    {
        minv = INF;
        u = -1;
        for (int i = 0; i < n; ++i)
        {
            if(minv > d[i] && color[i] != BLACK)
            {
                u = i;
                minv = d[i];
            }
        }
        if(u == -1)
            break;
        color[u] = BLACK;
        for (int v = 0; v < n; ++v)
        {
            if(color[v] != BLACK && M[u][v] != INF)
            {
                if(d[v] > M[u][v])
                {
                    d[v] = M[u][v];
                    p[v] = u;
                    color[v] = GRAY;
                }
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if(p[i] != -1)
            sum += M[i][p[i]];
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    //freopen("sample.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int e; cin >> e;
            M[i][j] = (e == -1) ? INF : e;
        }
    }
    cout << prim() << endl;
    return 0;
}