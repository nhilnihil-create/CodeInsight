#include <bits/stdc++.h>
using namespace std;
#define f(i,j,k) for(int i=j;i<k;i++)
int main(){
    long long a,b,m,x,y,c;
    cin>>a>>b>>m;
    long long aa[a],bb[b],ans[m];
    f(i,0,a){
        cin>>aa[i];
    }
    f(i,0,b){
        cin>>bb[i];
    }
    f(i,0,m){
        cin>>x>>y>>c;
        ans[i]=aa[x-1]+bb[y-1]-c;
    }
    sort(aa,aa+a);
    sort(bb,bb+b);
    sort(ans,ans+m);
    cout<<min(aa[0]+bb[0],ans[0])<<endl;
    return 0;
}