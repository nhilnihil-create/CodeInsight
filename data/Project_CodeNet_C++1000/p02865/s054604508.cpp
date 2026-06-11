/*
 *  Author : Jun_SH
 *  12/11/2019
 */
#include<bits/stdc++.h>
#pragma GCC optimize(3,"Ofast","inline")
#define int long long
using namespace std;
inline int read(){
    int f=1,x=0;char ch=getchar();
    while(ch<'0'&&ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    cout<<(n-1)/2<<endl;
}
