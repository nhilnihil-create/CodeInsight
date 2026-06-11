#include<bits/stdc++.h>
using namespace std;

const int mn=3e5+6;
int n,m,cnt,cntn[mn],cntm[mn],idn[mn],idm[mn];
map<pair<int,int>,bool> vis;

bool cmpn(int a,int b) {return cntn[a]>cntn[b];}
bool cmpm(int a,int b) {return cntm[a]>cntm[b];}

int main()
{
    scanf("%d%d%d",&n,&m,&cnt);
    int a,b;
    for(int i=1;i<=cnt;++i) {
        scanf("%d%d",&a,&b);
        cntn[a]++,cntm[b]++;
        vis[make_pair(a,b)]=1;
    }
    for(int i=1;i<=n;++i) idn[i]=i;
    for(int i=1;i<=m;++i) idm[i]=i;
    sort(idn+1,idn+n+1,cmpn);
    sort(idm+1,idm+m+1,cmpm);
    int lasn=1,lasm=1;
    for(int i=2;i<=n;++i) {if(cntn[idn[i]]==cntn[idn[lasn]]) lasn++;else break;}
    for(int i=2;i<=m;++i) {if(cntm[idm[i]]==cntm[idm[lasm]]) lasm++;else break;}
    if(lasn*lasm>cnt) {printf("%d",cntn[idn[lasn]]+cntm[idm[lasm]]);return 0;}
    for(int i=1;i<=lasn;++i) for(int j=1;j<=lasm;++j) {
        if(!vis[make_pair(idn[i],idm[j])]) {printf("%d",cntn[idn[lasn]]+cntm[idm[lasm]]);return 0;}
    }
    printf("%d",cntn[idn[lasn]]+cntm[idm[lasm]]-1);return 0;
}