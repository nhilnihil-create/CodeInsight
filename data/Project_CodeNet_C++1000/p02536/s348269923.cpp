#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct UnionFind{
    vector<int> d;
    UnionFind(int n): d(n, -1) {}
    int find(int x){
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    bool unite(int x, int y){
        x = find(x);
        y = find(y);
        
        if (x == y) return false;
        if (d[x] > d[y]) swap(x, y);
        
        d[x] += d[y];
        d[y] = x;
        return false;
    }
    bool same(int x, int y){
        x = find(x);
        y = find(y);
        
        if (x == y) return true;
        return false;
    }
    int size(int x){
        return -d[find(x)];
    } 
};

int main(void){
    int N, M, cnt;
    cin >> N >> M;
    UnionFind uf(N);
    
    for (int i = 0; i < M; i++){
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        
        if (!uf.same(A, B)){
            uf.unite(A, B);
        }
    }
    
    cnt = 0;
    for (int i = 0; i < N; i++){
        if (uf.find(i) == i) cnt++;
    }
    
    cout << cnt - 1 << endl;
    
    return 0;
}
