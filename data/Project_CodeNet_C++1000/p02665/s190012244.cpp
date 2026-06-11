#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll ,int>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 2e5+5;
const ll mod=998244353;
ll n,a[maxn],b[maxn],m;
string s;
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<=n;i++){
        cin>>a[i];
    }
    if(!n&&a[0]!=1||n&&a[0]||a[n]==0){
        cout<<-1;
        return 0;
    }
    for(int i=n;i;i--){
        b[i]=b[i+1]+a[i];//i~n有几个叶子节点
    }
    ll x=1;//当前非叶节点数
    m=0;//答案
    for(int i=0;i<n;i++){
        x-=a[i];//最大
        x=min(x,b[i+1]);
        if(x<=0){
            cout<<-1;
            return 0;
        }
        m+=x;
        m+=a[i];
        x*=2ll;
    }
    x-=a[n];
    x=min(x,b[n+1]);
    if(x!=0){
        cout<<-1;
        return 0;
    }
    m+=a[n];
    cout<<m<<'\n';
    return 0;
}
