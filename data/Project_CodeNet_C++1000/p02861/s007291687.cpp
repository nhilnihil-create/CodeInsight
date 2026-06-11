#include<bits/stdc++.h>
using namespace std;

#define rep(i,n)  for(int i=0;i<n;++i)
#define sc1(a)  scanf("%d",&a)
#define sc2(a,b)  scanf("%d %d",&a,&b)
#define sc3(a,b,c)  scanf("%d %d %d",&a,&b,&c)

int main(){
    int n,cnt=0;
    int d[8][2];
    double ans=0.0;
    sc1(n);
    vector <int>  p(n);
    rep(i,n) p[i]=i;
    rep(i,n) sc2(d[i][0],d[i][1]);
    do {
        //printf("%d %d %d\n",p[0],p[1],p[2]);
        cnt++;
        rep(i,n-1) ans+=pow(pow(d[p[i+1]][0]-d[p[i]][0],2)+pow(d[p[i+1]][1]-d[p[i]][1],2),0.5);
    } while (next_permutation(p.begin(),p.end()));

    printf("%.15lf\n",ans/(cnt*1.0));
    return 0;
}
