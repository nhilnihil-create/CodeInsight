//Kruskal's algorithm
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct E
{
    int weight;
    int begin;
    int end;
};

struct Unionfind
{
    vector<int> parents;

    Unionfind(int n) : parents(n)
    {
        for (int i = 0; i < n; i++)
        {
            parents[i] = i;
        }
    }

    int root(int x)
    {
        if (parents[x] == x)
        {
            return x;
        }
        return parents[x] = root(parents[x]);
    }

    void unite(int x, int y)
    {
        int par_x = root(x);
        int par_y = root(y);
        if (par_x == par_y)
        {
            return;
        }
        parents[par_x] = par_y;
    }

    bool same(int x, int y)
    {
        int par_x = root(x);
        int par_y = root(y);
        return par_x == par_y;
    }
};

int main()
{
    int n;
    cin >> n;
    struct Unionfind tree(n);

    vector<E> e(n * (n - 1) / 2);
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int temp;
            cin >> temp;
            if (i < j)
            {
                e[index].weight = temp;
                e[index].begin = i;
                e[index].end = j;
                index++;
            }
        }
    }

    sort(e.begin(), e.end(),
         [](const E &l, const E &r) {
             return l.weight < r.weight;
         });

    int ans = 0;
    for (int i = 0; i < e.size(); i++)
    {
        if (e[i].weight == -1)
        {
            continue;
        }

        if (tree.same(e[i].begin, e[i].end))
        {
            continue;
        }
        else
        {
            tree.unite(e[i].begin, e[i].end);
            ans += e[i].weight;
        }
    }

    cout << ans << endl;
}

/*

<INPUT>
5
 -1 2 3 1 -1
 2 -1 -1 4 -1
 3 -1 -1 1 1
 1 4 1 -1 3
 -1 -1 1 3 -1

<OUTPUT>
5

*/

