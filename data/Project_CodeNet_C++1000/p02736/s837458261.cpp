#include<cstdio>
#define For(i,A,B) for(i=(A);i<=(B);++i)
const int N=1000050;
int a[N],b[N],cnt;
inline int Abs(int x){return x<0?-x:x;}
inline void work(int x,int k){
    if(x)for(;!(x&1);x>>=1)cnt+=k;
}
inline bool check(int *a,int n){
    int i;
    bool f=0;
    cnt=0;
    For(i,1,n){
        if(!cnt&&(a[i]&1))f^=1;
        work(n-i,1);
        work(i,-1);
    }
    return f;
}
int main(){
    int n,i;
    bool f=0,g=0;
    scanf("%d",&n);
    For(i,1,n)scanf("%1d",a+i);
    if(check(a,n)){
        puts("1");
        return 0;
    }
    For(i,2,n){
        if(Abs(a[i]-a[i-1])==1){
            puts("0");
            return 0;
        }
        b[i-1]=Abs(a[i]-a[i-1])>>1;
    }
    puts(check(b,n-1)?"2":"0");
    return 0;
}