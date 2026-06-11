
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <sstream>
#include <string>
#include <functional>
#include <queue>
#include <deque>
#include <stack>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <fstream>
#include <iterator>
#include <random>
#include <chrono>


#define forr(i,start,count) for (int i = (start); i < (start)+(count); ++i)
#define set_map_includes(set, elt) (set.find((elt)) != set.end())
#define readint(i) int i; cin >> i
#define readll(i) ll i; cin >> i
#define readdouble(i) double i; cin >> i
#define readstring(s) string s; cin >> s

typedef long long ll;

using namespace std;

ll modd = 1000 * 1000 * 1000 + 7;

class UnionFind {
    public:
      vector<int> parent;
      vector<int> size;
//      size[i] = number of nodes in tree rooted at i
// Note: not necessarily correct if i is not a root node
      set<int> roots;

    UnionFind(int n) : parent(n), size(n) {
        forr(i,0,n) { roots.insert(i); }
        forr(i,0,n) {
            parent[i] = i; size[i] = 1;
        }
    } 

    int Find(int p) {
        int root = p;
        while (root != parent[root]) {  root = parent[root]; }
        while (p != root) {
            int newp = parent[p];
            parent[p] = root;
            p = newp;
        }
        return root;
    }

    void Union(int p, int q) {
        int rootP = Find(p);
        int rootQ = Find(q);
        if (rootP == rootQ) return;

        if (size[rootP] < size[rootQ]) {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
            roots.erase(rootP);
        }
        else {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
            roots.erase(rootQ);
        }
    }

};



int main()   {

      ios_base::sync_with_stdio(false);

      cout.precision(17);
      mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
      uniform_int_distribution<int> rand_gen(0, modd);   // rand_gen(rng) gets the rand no

//    readint(test_cases);
    int test_cases = 1;
    forr(t, 1, test_cases) {
        readint(n); readint(q);
        UnionFind uf(n);
        forr(i,0,q) {
            readint(a); readint(u); readint(v);
            if (a==0) {
                uf.Union(u,v);
            }
            if (a==1) {
                cout << (uf.Find(u) == uf.Find(v)) << endl;
            }
        }        
    }
    return 0;
}
