#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, q, i, ans[200100]={0}, cnt=0;
    cin >> n >> q;
    atcoder :: dsu d(n);
    for(i=0;i<q;i++){
        int t, u, v;
        cin >> t >> u >> v;
        if(t==0) d.merge(u, v);
        else if(d.same(u, v)){
            ans[cnt]=1;
            cnt++;
        }
        else{
            ans[cnt]=0;
            cnt++;
        }
    }
    for(i=0;i<cnt;i++){
        cout << ans[i] <<endl;
    }
    return 0;
}
