#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

class UnionFind{
    private:
        unsigned int n_node;
        std::vector<uint32_t> parent, rank;

    public:
        UnionFind(unsigned int n){
            n_node = n;
            parent.resize(n);
            for(int i = 0; i < n; ++i) parent[i] = i;
            rank.resize(n, 0);
        }

        unsigned int find(unsigned int n){
            if(parent[n] == n) return n;
            else return parent[n] = find(parent[n]);
        }

        void unite(unsigned int m, unsigned int n){
            m = find(m);
            n = find(n);
            if(m == n) return;
            if(rank[m] < rank[n]) parent[m] = n;
            else{
                parent[n] = m;
                if(rank[m] == rank[n]) ++rank[m];
            }
            return;
        }

        unsigned int getRoot(unsigned int n){return find(n);}
};

int vmax(const std::vector<int>& v){
    int ret = 0xffffffff;
    for(int i = 0; i < v.size(); ++i) ret = std::fmax(ret, v[i]);
    return ret;
}

int main(void){
    int n, m;
    cin >> n >> m;
    UnionFind uf(n);
    for(int i = 0; i < m; ++i){
        int tmp, tmp2;
        cin >> tmp >> tmp2;
        uf.unite(tmp - 1, tmp2 - 1);
    }
    vector<int> v(n, 0);
    for(int i = 0; i < n; ++i){
        ++v[uf.getRoot(i)];
    }
    cout << vmax(v) << endl;
    return 0;
}