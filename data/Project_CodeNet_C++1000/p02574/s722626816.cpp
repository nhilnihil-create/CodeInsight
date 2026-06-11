#include <cstdio>
int n,a,d,t[1000003],maxa=-(1<<30);
//maxa保存a的最大值，也是因子的最大值，t[i]表示因子i有多少个，d为n个数的最大公因数
int gcd(int x,int y){
    if(!y) return x;
    return gcd(y,x%y);
}
void fj(int x){//分解质因数
    for(int i=2;i*i<=x;){
        if(!(x%i)){
            ++t[i];//用桶记下来
            while(!(x%i)) x/=i;
        }
        else ++i;
    }
    if(x>1) ++t[x];//不要忘了这一句
}
int main(){
    scanf("%d%d",&n,&a);
    d=a;//d初始值为a
    for(int i=2;i<=n;i++){
        scanf("%d",&a);
        if(maxa<a) maxa=a;//更新maxa
        d=gcd(d,a);//求n个数的公因数可以这么做
        fj(a);//对a分解质因数
    }
    if(d==1){
        for(int i=2;i<=maxa;i++)
            if(t[i]>1) return puts("setwise coprime"),0;
            //t[i]>1说明有几个数有相同的因子，则肯定有一对数不互质
        return puts("pairwise coprime"),0;
    }
    else return puts("not coprime"),0;
    return 0;
}

