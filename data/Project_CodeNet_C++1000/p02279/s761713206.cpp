#include <stdio.h>
#include <iostream>
#include <utility>
#include <algorithm>
#include <math.h>
#include <vector>
#include <list>
using namespace std;

int n;
struct node
{
    int parent, depth;
    vector<int> child;
};
node nd[100000];

void CalcDepth(int r)
{
    if (nd[r].child.size() != 0)
    {
        for (int i = 0; i < nd[r].child.size(); i++)
        {
            nd[nd[r].child[i]].depth = nd[r].depth + 1;
            CalcDepth(nd[r].child[i]);
        }
    }

    return;
}

int main()
{
    cin >> n;
    int x, y, k;
    for (int i = 0; i < n; i++)
    {
        nd[i].parent = -1;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> x >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> y;
            nd[x].child.push_back(y);
            nd[y].parent = x;
        }
    }

    int r = 0;
    while (nd[r].parent > -1)
    {
        r = nd[r].parent;
    }
    nd[r].depth = 0;
    CalcDepth(r);

    for (int i = 0; i < n; i++)
    {
        printf("node %d: parent = %d, depth = %d,", i, nd[i].parent, nd[i].depth);
        if (nd[i].parent == -1)
            printf(" root,");
        else if (nd[i].child.size() == 0)
            printf(" leaf,");
        else
            printf(" internal node,");

        printf(" [");
        for (int j = 0; j < nd[i].child.size(); j++)
        {
            if (j)
                printf(" ");
            printf("%d", nd[i].child[j]);
            if (j != nd[i].child.size() - 1)
                printf(",");
        }
        printf("]\n");
    }

    return 0;
}
