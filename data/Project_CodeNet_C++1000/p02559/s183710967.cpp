#include<iostream>
#include<atcoder/all>

using namespace std;
using namespace atcoder;

int main(){
    int n, q;
    fenwick_tree<long long> fw(500050);
    cin >> n >> q;
    for (int i = 0; i < n;i++){
        int a;
        cin >> a;
        fw.add(i, a);
    }
    int t, u, v;

    for (int i = 0; i < q;i++){
        cin >> t >> u >> v;
        if(t == 0){
            fw.add(u, v);
        }else{
            fw.sum(u, v);
            cout << fw.sum(u, v) << endl;
        }
    }

    return 0;
}