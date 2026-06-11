#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxm=2e5+5;
struct Node{
    int a,b;
}e[maxm];
int n;
bool cmp(Node a,Node b){
    if(a.b!=b.b)return a.b>b.b;
    return a.a>b.a;
}
signed main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>e[i].a>>e[i].b;
    }
    sort(e+1,e+1+n,cmp);
    int cur=e[1].b;
    for(int i=1;i<=n;i++){
        int a=e[i].a,b=e[i].b;
//        cout<<cur<<' '<<a<<' '<<b<<endl;
        if(cur>b)cur=b;
        if(cur-a<0){
            cout<<"No"<<endl;
            return 0;
        }
        cur-=a;
    }
    cout<<"Yes"<<endl;
    return 0;
}
/*

*/
