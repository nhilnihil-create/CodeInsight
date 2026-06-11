#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <array>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
#include <memory>
#include <regex>
using namespace std;

class UnionFindTree
{
private:
    int n;
    int groupNum;       // グループの数
    vector<int> parent; // 親ノード
    vector<int> rank;   // 木の高さの上限
    vector<int> num;    // グループの要素数
    int find(int i){
        if(parent[i] == i)
            return i;
        else
            return parent[i] = find(parent[i]);
    }
public:
    UnionFindTree(int n){ // コンストラクタ
        this->n = n;
        groupNum = n;
        parent.resize(n);
        for(int i=0; i<n; ++i)
            parent[i] = i;
        rank.assign(n, 0);
        num.assign(n, 1);
    }
    void unite(int a, int b){ // aとbのグループを併合
        if((a = find(a)) != (b = find(b))){
            if(rank[a] < rank[b]){
                parent[a] = b;
                num[b] += num[a];
            }
            else{
                parent[b] = a;
                if(rank[a] == rank[b])
                    ++ rank[a];
                num[a] += num[b];
            }
            -- groupNum;
        }
    }
    bool same(int a, int b){ // aとbのグループが同じかを調べる
        return find(a) == find(b);
    }
    int getNum(){ // グループの数を返す
        return groupNum;
    }
    int getNum(int a){ // aのグループの要素数を返す
        return num[find(a)];
    }
};

int main()
{
    int n, q;
    cin >> n >> q;

    UnionFindTree uft(n);
    for(int i=0; i<q; ++i){
        int t, u, v;
        cin >> t >> u >> v;

        if(t == 0)
            uft.unite(u, v);
        else
            cout << (uft.same(u, v) ? 1 : 0) << endl;
    }

    return 0;
}
