#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
typedef long long ll;
using namespace std;
char c[2020][2020];
int l[2020][2020];
int r[2020][2020];
int u[2020][2020];
int d[2020][2020];
int main(){
    memset(l,0,sizeof l);
    memset(r,0,sizeof r);
    memset(u,0,sizeof u);
    memset(d,0,sizeof d);
    int h,w,t=0;cin>>h>>w;
    for(int i=1;i<=h;i++) 
    for(int j=1;j<=w;j++)
    cin>>c[i][j];
    for(int i=1;i<=h;i++) 
    for(int j=1;j<=w;j++)
    if(c[i][j]=='.')
    {l[i][j]=l[i][j-1]+1;u[i][j]=u[i-1][j]+1;}
    for(int i=h;i>=1;i--) 
    for(int j=w;j>=1;j--)
    if(c[i][j]=='.')
    {d[i][j]=d[i+1][j]+1;r[i][j]=r[i][j+1]+1;}
    for(int i=1;i<=h;i++) 
    for(int j=1;j<=w;j++)
    if(c[i][j]=='.')
    t=max(t,l[i][j]+r[i][j]+u[i][j]+d[i][j]-3);
    cout<<t;
}