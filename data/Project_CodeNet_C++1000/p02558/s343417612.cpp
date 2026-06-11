#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0LL; X < (N); X++)
#define ALL(V) (V).begin(),(V).end()
#define endl "\n"

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

const double PI = 3.1415926535897932384626;
const double EPS = 1e-10;
const ll MODN = 1000000007;
const ll MODN2 = 998244353;

class UnionFind{
    vector<int> parent;
    vector<int> sizev;

public:
    UnionFind(){}
    UnionFind(int n){
        for(int i = 0; i < n; i++){
            parent.push_back(i);
            sizev.push_back(1);
        }
    }

    void merge(int a, int b){
        int pa = leader(a);
        int pb = leader(b);

        if(pa != pb){
            if(size(pa) < size(pb)) swap(pa, pb);
            parent[pb] = parent[pa];
            sizev[pb] += sizev[pa];
            sizev[pa] = sizev[pb];
        }
    }

    bool same(int a, int b){
        return leader(a) == leader(b);
    }

    int leader(int a){
        int tmp = parent[a];
        if(tmp == a) return a;

        tmp = leader(tmp);
        parent[a] = tmp;
        return tmp;
    }

    int size(int a){
        return sizev[leader(a)];
    }

    vector<vector<int>> groups(){
        vector<int> index(parent.size(), -1);
        int count = 0;
        for(int i = 0; i < parent.size(); i++){
            if(i == leader(i)){
                index[i] = count;
                count++;
            }
        }
        vector<vector<int>> result(count + 1);

        for(int i = 0; i < parent.size(); i++){
            int tmp = leader(i);
            result[index[tmp]].push_back(i);
        }

        return result;
    }
};

int main(){

    int n, q;
    cin >> n >> q;

    UnionFind uf(n);

    rep(i, q){
        int t,u,v;
        cin >> t >> u >> v;

        if(t == 0){
            uf.merge(u, v);
        }else{
            cout << (uf.same(u,v) ? 1 : 0) << endl;
        }
    }

    return 0;
}
