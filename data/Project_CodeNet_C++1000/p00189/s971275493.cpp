#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <map>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>

using namespace std;

#if 1
#define PRINT(x) { cout << #x << ": " << (x) << endl; }
#define PRINT_CONTAINER(x)  { cout << #x << ": ";                       \
        for (size_t ix = 0; ix < (x).size(); ++ix) cout << (x)[ix] << ", "; \
        cout << endl; }
#else
#define PRINT(x)
#define PRINT_CONTAINER(x)
#endif

int n;
struct Edge
{
    int from;
    int to;
    int cost;
};
vector<Edge> es;
vector<int> ds;

// Bellman-Ford algorithm that computes shortest paths from a single
// source vertex to all of the other vertices in a weighted digraph.
void shortest_path_bf(int s)
{
    fill(ds.begin(), ds.end(), INT_MAX);
    ds[s] = 0;
    while (true)
    {
        bool update = false;
        for (int i = 0; i < es.size(); ++i)
        {
            const Edge& e = es[i];
            if (ds[e.from] != INT_MAX && ds[e.to] > ds[e.from] + e.cost)
            {
                ds[e.to] = ds[e.from] + e.cost;
                update = true;
            }
        }
        if (!update) break;
    }
}

int main(int argc, char *argv[])
{
    while (true)
    {
        scanf("%d", &n);
        if (n == 0) break;
        es.clear();
        int num_town = 0;
        for (int i = 0; i < n; ++i)
        {
            Edge e;
            scanf("%d%d%d", &e.from, &e.to, &e.cost);
            num_town = max(max(num_town, e.from), e.to);
            es.push_back(e);
            swap(e.from, e.to);
            es.push_back(e);
        }
        ds.resize(num_town + 1);
        int min_town;
        int min_value = INT_MAX;
        for (int i = 0; i < ds.size(); ++i)
        {
            shortest_path_bf(i);
            int val = 0;
            for (int j = 0; j < ds.size(); ++j)
            {
                if (ds[j] != INT_MAX) val += ds[j];
            }
            if (val < min_value)
            {
                min_value = val;
                min_town = i;
            }
        }
        printf("%d %d\n", min_town, min_value);
    }
}

