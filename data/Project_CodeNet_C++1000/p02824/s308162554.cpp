#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll n,m,v,p;
ll a[100200];
ll b[100200];
bool cmp(ll a,ll b){ return a>b; }
int check(ll mid){
    if(mid<=p) return 1;
    if(a[mid]+m<a[p]) return 0;
    if(v<=p-1) return 1;
    for(int i = 1 ; i <= n ; i ++ ) b[i] = a[i];
    ll sum = 0;
    for(int i = 1 ; i <= p-1 ; i ++ ){
        b[i] += m;
        sum += m; //计算前面能吞掉多少贡献
    }
    int dis=v-p+1; // 还剩下个数
    for(int i = n ; i > mid ; i -- ){
        if(dis==1) break;//只能给mid
        sum += m ;
        dis--;
        b[i]+=m;
    }
    sum += m ;// mid消化掉
    ll flag = a[mid]+m;
    ll st = m*v-sum;//剩余量
    for(int i = p ; i < mid ; i ++ ){
        int up = min(m,max(a[mid]+m-a[i],0ll));
        if(up > st) up = st;//不够量
        st -= up;
        b[i] += up;
    }
    if( a[mid]+m>=b[p] && st<=0 ) return 1;
    return 0;
}
int main()
{
    cin >> n >> m >> v >> p;
    for(int i = 1 ; i <= n ; i ++ ){
        cin >> a[i];
    }
    sort(a+1,a+1+n,cmp);//前P个
    ll l = 1 , r = n;
    ll mid ;
    ll ans = 0;
    while(l<=r){
        mid = (l+r)>>1;
        if(check(mid)){
            l = mid+1;
            ans = mid;
        }
        else r = mid-1;
    }
    cout<<ans<<endl;
}
