#include<bits/stdc++.h>
using namespace std;

const int N = 500 + 5;
int edge[N][N];

void gao(int a, int b,int cnt) {
    if(a>=b)
    return;
    int ls=a,le=(a+b)/2;
    int rs=le+1,re=b;
    for(int i=ls;i<=le;i++)
        for(int j=rs;j<=re;j++)
        edge[i][j]=edge[j][i]=cnt;
    gao(ls,le,cnt+1);
    gao(rs,re,cnt+1);
}

int main() {
    int n;
    cin>>n;
    gao(1, n,1);
    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(j!=i+1)
            cout<<" ";
            cout<<edge[i][j];
        }
        
        cout<<endl;
    }
}