/*
 *  Author : Jun_SH
 *  Solution for ddcc2020-qual D
 */
#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    int f=1,x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
int a[10];
main(){
    int m=read();
    int sum=0;
    int d=0;
    for(int i=1;i<=m;++i){
        int x,y;
        cin>>x>>y;
        a[x]+=y;
        sum+=x*y;
        d+=y;
    }
    cout<<(d-1)+(sum-1)/9<<endl;

}
