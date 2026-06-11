#include <bits/stdc++.h>
#include "atcoder/all"
using namespace std;

int main(){
    int n, q;
    cin >> n >> q;
    atcoder::fenwick_tree<uint64_t> ft{n};
    for(int i=0;i<n;++i){
        uint64_t a;
        cin >> a;
        ft.add(i, a);
    }
    for(int i=0;i<q;++i){
        int t;
        uint64_t a, b;
        cin >> t >> a >> b;
        if(t == 0) ft.add(a, b);
        else cout << ft.sum(a, b) << "\n";
    }

    return 0;
}