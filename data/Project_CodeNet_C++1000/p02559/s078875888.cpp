#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

typedef long long ll;
typedef unsigned long long ull;

int main()
{
    ll N, Q;
    cin >> N >> Q;
    fenwick_tree<ll> fw(N);
    ll ai;
    for(int i=0;i<N;i++){
        cin >> ai;
        fw.add(i, ai);
    }
    ll q0, q1, q2;
    vector<ll> res;
    for(int i=0;i<Q;i++){
        cin >> q0 >> q1 >> q2;
        if(q0 == 0){
            fw.add(q1, q2);
        }else if(q0 == 1){
            res.push_back(fw.sum(q1, q2));
        }else{
            abort();
        }
    }
    for(auto v : res) cout << v << endl;

    return 0;
}