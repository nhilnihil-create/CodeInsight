#include<bits/stdc++.h>
using namespace std;

#define rep(i,n)  for(int i=0;i<n;++i)
#define sc1(a)  scanf("%d",&a)
#define sc2(a,b)  scanf("%d %d",&a,&b)
#define sc3(a,b,c)  scanf("%d %d %d",&a,&b,&c)

int main(){
    int n,x,y,cnt=0;
    sc1(n);
    vector <int> d(n);
    vector <int> p(n);
    vector <int> q(n);
    rep(i,n) d[i]=i+1;
    rep(i,n) sc1(p[i]);
    rep(i,n) sc1(q[i]);
    do {
        int w[2]={1,1};
        rep(i,n){
            if (p[i]!=d[i]) w[0]=0;
            if (q[i]!=d[i]) w[1]=0;
        }
        if (w[0]) x=cnt;
        if (w[1]) y=cnt;
        cnt++;

    } while(next_permutation(d.begin(),d.end()));
    printf("%d\n",abs(x-y));
    return 0;
}