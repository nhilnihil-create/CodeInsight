#include<bits/stdc++.h>
#include<atcoder/dsu>
using namespace std;
using namespace atcoder;
int main(){
    int n, q;
    cin >> n >> q;
    dsu d(n);
    for(int i = 0; i < q; i++){
        int s, t, u;
        cin >> s >> t >> u;
        if(s == 0)
            d.merge(t, u);
        else{
            if(d.same(t, u))
                cout << 1 << endl;
            else 
                cout << 0 << endl;
        }
    }
    return 0;
}