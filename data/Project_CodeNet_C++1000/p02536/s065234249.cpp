#include <iostream>
#include <atcoder/dsu>

using namespace std;
using namespace atcoder;

int main(void) {
    int n, m;
    cin >> n >> m;

    dsu graph = dsu(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph.merge(a - 1, b - 1);
    }
    
    cout << graph.groups().size() - 1 << endl;
}
