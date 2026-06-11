#include <iostream>
#include <atcoder/dsu>

using namespace std;

int main(){
    int N,Q;
    cin >> N >> Q;
    int query[Q][3];
    for(int i = 0; i < Q; i++){
        cin >> query[i][0]  >> query[i][1] >> query[i][2];
    }
    atcoder::dsu d(N);
    for(int i = 0; i < Q; i++){
        int u = query[i][1];
        int v = query[i][2];
        if(query[i][0] == 0){
            d.merge(u, v);
        }
        else{
            cout << d.same(u, v) << endl;
        }         
    }  
}