#include<iostream>
#include<algorithm>
using namespace std;
int fa[100000+5];
int find(int a){
    return a==fa[a]?a:fa[a]=find(fa[a]);
}
void merge(int a,int b){
    fa[find(a)]=find(b);
}
int main(){
    int n,m,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        merge(a,b);
    }
    for(int i=1;i<=n;i++){
        if(find(i)==i)
            cnt++;
    }
    cout<<cnt-1;
    //getchar();
    //getchar();
    return 0;
}