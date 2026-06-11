#include <cstdio>
#include<iostream>
using namespace std;
typedef long long ll;


char ss[200010];
ll record[10010];
ll res=0;
int main(){
    int n,p,k=0,d=1;

    scanf("%d%d%s",&n,&p,ss);

    if(p==2||p==5){
        for(ll i=0;i<n;i++)
            if((ss[i]-'0')%p==0)
                res+=i+1;
    }
    else{
        record[0]=1;
        for(ll i=n-1;i>=0;i--){
            k+=(ss[i]-'0')*d;
            k%=p;
            res+=record[k];
            record[k]++;
            d=d*10%p;
        }
    }
    printf("%lld",res);
}
