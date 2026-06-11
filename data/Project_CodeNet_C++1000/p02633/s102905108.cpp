#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e5+1000;
ll t;
int main(){
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    ll res=1;
    for(;;res++){
        if(res*360%t==0) break;
    }res=res*360/t;
    cout<<res<<endl;
    return 0;
}
