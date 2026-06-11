#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <limits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstdint>
#include <cassert>

using namespace std;

#define FOR(i, start, end) for(int i = (start); i < (end); ++i)
#define REP(i, n) FOR(i, 0, n)

struct Node {
    int parent;
    vector<int> children;
    Node() : parent(-1), children() {}
};

vector<Node> read_problem()
{
    int n;
    scanf("%d\n", &n);

    vector<Node> nodes(n);
    REP(i, n) {
        int id;
        int k;
        scanf("%d %d", &id, &k);
        Node& node = nodes[id];

        REP(j, k) {
            int child;
            scanf("%d", &child);
            node.children.emplace_back(child);
            nodes[child].parent = id;
#if 0
            printf("%d %d %lu\n", id, child, node.children.size());
#endif
        }
    }

    return nodes;
}

int depth(const vector<Node>& nodes, int id)
{
    int d = 0;
    for(Node node = nodes[id]; node.parent != -1; node = nodes[node.parent]) {
        ++d;
    }

    return d;
}

string node_typ(const Node& node)
{
    if(node.parent == -1)
        return "root";
    else if(node.children.empty())
        return "leaf";
    else
        return "internal node";
}

int main()
{
    vector<Node> nodes = read_problem();
    int n = nodes.size();

    REP(i, n) {
        Node& node = nodes[i];
        int k = node.children.size();
        int d = depth(nodes, i);
        string typ = node_typ(node);

        printf("node %d: parent = %d, depth = %d, %s, [", i, node.parent, d, typ.c_str());
        REP(j, k) {
            printf("%d%s", node.children[j], j == k-1 ? "" : ", ");
        }
        puts("]");
    }

    return 0;
}