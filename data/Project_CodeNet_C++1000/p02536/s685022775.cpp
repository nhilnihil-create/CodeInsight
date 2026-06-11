#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define For(i,a,b) for(int i = a;i<=b;i++)
typedef pair<int,int> PII;
const int N = 100000 + 5;
int pre[N];
void init(int l){
    For(i,1,l) pre[i] = i;
}
int Find(int x){
    int p,tmp;
    p = x;
    while(x != pre[x]){
        x = pre[x];
    }
    while(x != p){
        tmp = pre[p];
        pre[p] = x;
        p = tmp;
    }
    return x;
}
void join(int x,int y){
    int q = Find(x);
    int p = Find(y);
    if(q != p) pre[q] = p;
}
bool same(int x,int y){
    return Find(x) == Find(y);
}
int n,m;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>m;
    init(n);
    while(m--){
        int a,b;
        cin>>a>>b;
        join(a,b);
    }
    int cnt = 0;
    For(i,1,n){
        if(i == pre[i]) cnt++;
    }
    cout<<cnt-1<<endl;
    system("pause");
    return 0;
}