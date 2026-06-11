#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e5+100;
const ll inf=0x3f3f3f3f3f3f3f3f;
ll t,n,m,a[maxn];
int main(){
    //freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    ll res=0;
    for(int i=0;i<t;i++){
        cin>>a[i];
    } 
    sort(a,a+t,greater<int>());
    res=a[0];
    for(int i=1;i<=t/2-1;i++) res+=a[i]*2;
    if(t&1) res+=a[t/2];
    cout<<res<<endl;
    return 0;
}
