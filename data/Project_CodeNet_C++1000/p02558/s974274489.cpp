#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;

int main(){
    int n,q;
	cin >> n >> q;
    atcoder::dsu uf(n);
    int t,u,v;
    for(int i=0;i<q; i++){
        cin >> t >> u >> v;
        if(t)cout << uf.same(u,v) << endl;
        else uf.merge(u, v);
    }
}