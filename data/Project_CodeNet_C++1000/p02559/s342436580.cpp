//フェニック木　Binary Indexed Tree;
#include <iostream>
#include <atcoder/fenwicktree>
using namespace std;
using namespace atcoder;

int main(){
    int N, Q;
    cin >> N >> Q;
    fenwick_tree<long long> fw(N);
    for(int i = 0; i < N; i++){
        long long a;
        cin >> a;
        fw.add(i, a);
    }
    for(int i = 0; i < Q; i++){
        bool b; long long u; long long v;
        cin >> b >> u >> v;
        if(b){
            cout << fw.sum(u, v) << endl;
        }
        else{
            fw.add(u, v);
        }
    }
    return 0;
}