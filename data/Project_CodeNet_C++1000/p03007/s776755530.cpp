#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
#define MAX 100100
inline int read()
{
    int x=0;bool t=false;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
    if(ch=='-')t=true,ch=getchar();
    while(ch<='9'&&ch>='0')x=x*10+ch-48,ch=getchar();
    return t?-x:x;
}
int n,a[MAX],b[MAX],s;
vector<pair<int,int> > T;
int main()
{
    n=read();
    for(int i=1;i<=n;++i)a[i]=read();
    sort(&a[1],&a[n+1]);
    for(int i=2;i<n;++i)b[i]=a[i]<0;
    b[1]=1;b[n]=0;
    for(int i=2;i<n;++i)
        if(b[i])T.push_back(make_pair(a[n],a[i])),a[n]-=a[i];
        else T.push_back(make_pair(a[1],a[i])),a[1]-=a[i];
    T.push_back(make_pair(a[n],a[1]));
    printf("%d\n",a[n]-a[1]);
    for(auto a:T)printf("%d %d\n",a.first,a.second);
    return 0;
}