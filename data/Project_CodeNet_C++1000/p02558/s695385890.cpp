#include <atcoder/all>
using namespace std;
using namespace atcoder;
int main()
{
    int n, q;
    cin >> n >> q;
    dsu uf(n);
    for(int i = 0; i < q; i++)
    {
        int t, u, v;
        cin >> t >> u >> v;
        if(t == 0)
        {
            uf.merge(u, v);
        }
        else
        {
            if(uf.same(u, v)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
}
