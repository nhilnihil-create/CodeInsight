/*
 * @Author: RBQRBQ
 * @Date: 2020-04-15 14:04:58
 * @LastEditors: RBQRBQ
 * @LastEditTime: 2020-04-15 14:18:47
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> pii;
namespace IO{
    template<typename T>inline void read(T &x){
        x=0;ll f=1;char ch=getchar();
        while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
        while(isdigit(ch)){x=x*10+ch-48;ch=getchar();}
        x=x*f;
    }
}
using namespace IO;

ll n,m,w,h;
int main()
{
    read(n),read(m),read(w),read(h);
    for(int i=1;i<=n-h;i++)
    {
        for(int j=1;j<=m-w;j++)
        cout<<"1";
        for(int j=m-w+1;j<=m;j++)
        cout<<"0";
        cout<<endl;
    }
    for(int i=n-h+1;i<=n;i++)
    {
        for(int j=1;j<=m-w;j++)
        cout<<"0";
        for(int j=m-w+1;j<=m;j++)
        cout<<"1";
        cout<<endl;
    }
}