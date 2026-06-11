#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

int main()
{
    int N, Q;
    cin >> N >> Q;
    dsu g(N);
    int ti, ui, vi;
    vector<int> res;
    for(int i=0;i<Q;i++){
        cin >> ti >> ui >> vi;
        if(ti == 0){
            g.merge(ui, vi);
        }else if(ti == 1){
            res.push_back(g.same(ui, vi));
        }else{
            abort();
        }
    }
    for(auto v : res) cout << v << endl;

    return 0;
}