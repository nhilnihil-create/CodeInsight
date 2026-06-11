#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define LL long long
#define Set(s,v) memset(s,v,sizeof(s))
using namespace std;
inline LL read(){
    LL ans=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-'){f=-1;}ch=getchar();}
    while(ch>='0'&&ch<='9'){ans=(ans<<3)+(ans<<1)+(ch^48);ch=getchar();}
    return ans*f;
}
void write(LL x){
    if(x<0){putchar('-');x=-x;}
    if(x>9){write(x/10);}
    putchar(x%10|48);
}
int n;
int main(){
    n=read();
    if(n-(n&-n)==0){
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    if(n&1){
        for (int i=2;i<=n;i++){
            printf("%d %d\n",1,i);
            printf("%d %d\n",i,(i^1)+n);
            if(i==2){
                printf("%d %d\n",(i^1)+n,n+1);
            }
        }
    }else{
        int temp=n;
        while(temp-(temp&-temp)!=0) temp-=(temp&-temp);
        for (int i=2;i<n;i++){
            printf("%d %d\n",1,i);
            printf("%d %d\n",i,(i^1)+n);
            if(i==2){
                printf("%d %d\n",(i^1)+n,n+1);
            }
            if(i==temp+1){
                printf("%d %d\n",i,n);
            }
            if(i==(n^temp)){
                printf("%d %d\n",i,n+n);
            }
        }
    }
    return 0;
}