#include <bits/stdc++.h>

#include <random>
using namespace std;
typedef double db;
int n;
db x[105],y[105];int id[105];
db abs(db x,db y){return sqrt(x*x+y*y);}
db sa(){
    shuffle(id+1,id+1+n, std::mt19937(std::random_device()()));
    db a=0,b=0;
    for(int i=1;i<=n;i++){
        if(abs(a+x[id[i]],b+y[id[i]])>=abs(a,b))a+=x[id[i]],b+=y[id[i]];
    }
    return abs(a,b);
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>x[i]>>y[i],id[i]=i;
    db ans=0;
    for(int i=1;i<=100000;i++)
        ans = max(ans,sa());
    printf("%.17f\n",ans);
}
