#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<(x)<<endl
#define fix cout<<fixed<<setprecision(20);
const int maxn=(int)1e6+5;
int vis[maxn];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    
    for(int gap=m,i=1;gap>=1;gap-=2){
        cout<<i<<' '<<i+gap<<endl;
        i++;
    }
    for(int gap=m-1,i=1+m+1;gap>=1;gap-=2){
        cout<<i<<' '<<i+gap<<endl;
        i++;
    }
}
/* 
性质 构造尝试*3
 */