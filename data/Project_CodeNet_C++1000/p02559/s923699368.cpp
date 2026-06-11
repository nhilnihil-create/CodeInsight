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
    int n,q,tmp,a,b,type;
    cin>>n>>q;
    fenwick_tree<long long> ft(n);
    for(int i=0;i<n&&cin>>tmp;i++){
        ft.add(i,tmp);
    }
    while(q--&&cin>>type>>a>>b){
        if(!type)
            ft.add(a,b);
        else
            cout<<ft.sum(a,b)<<"\n";
    }
    return 0;
}
