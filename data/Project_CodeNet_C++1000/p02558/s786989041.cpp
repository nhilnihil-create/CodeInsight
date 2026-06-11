#include<bits/stdc++.h>
#include<atcoder/all>
#define prArr(Arr,n) for(int _=0;_<n;_++)   cout<<(Arr)[_]<<" ";
using namespace std;
using namespace atcoder;
const int INF=(int)0x3f3f3f3f;
const int MOD=(int)1e9+7;
const double eps=1e-9;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,q,type,u,v;
    cin>>n>>q;
    dsu d(n);
    while(q--&&cin>>type>>u>>v){
        if(type==0)
            d.merge(u,v);
        else
            cout<<d.same(u,v)<<"\n";
    }
    return 0;
}
