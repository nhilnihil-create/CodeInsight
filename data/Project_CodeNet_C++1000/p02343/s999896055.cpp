#include <iostream>
#include <vector>

using namespace std;

class DisjointSet{
public:
    vector<int> p;
    DisjointSet(int n){
        p.resize(n);
        for(int i=0;i<n;i++){
            p[i] = i;
        }
    }

    void unite(int x,int y){
        x = findSet(x);
        y = findSet(y);
        
        p[x] = y;
    }
    
    bool same(int x,int y){
        return findSet(x) == findSet(y);
    }
    int findSet(int x){
        if(x!=p[x]){
            //p[x]??????????????????????????§??????????????????
            p[x] = findSet(p[x]);
        }
        return p[x];
    }
};
int main(int argc, const char * argv[]) {
    int n,q;
    cin >> n >> q;
    
    DisjointSet ds(n);
    for(int i=0;i<q;i++){
        int com,x,y;
        cin >> com >> x >> y;
        if(com == 0){
            ds.unite(x, y);
        }else{
            if(ds.same(x, y)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    
    return 0;
}