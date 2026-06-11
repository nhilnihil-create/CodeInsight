//注意关键，首先对于这种两个数求差的时候，求最大值的问题，一般需要让第一个数尽量大，第二个数尽量小，由此可以证明极点答案为B的倍数-1
//还有最简便的办法，就是打表找规律
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define LL long long 
using namespace std;
LL a,b,n;
int main(){
    
    cin>>a>>b>>n;
    LL x=min(b-1,n);
    cout<<a*x/b-a*(x/b);
    
    return 0;
    
}