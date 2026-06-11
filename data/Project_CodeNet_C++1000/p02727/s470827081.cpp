#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1e5+7;
int a[maxn],b[maxn];
vector<int> c;
int x,y,aa,bb,cc;
bool cmp(int d,int e){
    return d>e;
}
int main(){
    cin>>x>>y>>aa>>bb>>cc;
    for(int i=1;i<=aa;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=bb;i++){
        scanf("%d",&b[i]);
    }
    for(int i=1,t;i<=cc;i++){
       scanf("%d",&t);
       c.push_back(t);
    }
    sort(a+1,a+aa+1,cmp);
    sort(b+1,b+bb+1,cmp);
    for(int i=1;i<=x;i++){
        c.push_back(a[i]);
    }
    for(int j=1;j<=y;j++){
        c.push_back(b[j]);
    }
    sort(c.begin(),c.end(),cmp);
    long long ans=0;
    for(int i=0;i<x+y;i++){
        ans+=c[i];
    }
    cout<<ans<<endl;

}