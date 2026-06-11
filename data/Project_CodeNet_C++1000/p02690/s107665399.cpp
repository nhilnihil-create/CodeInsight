#include <bits/stdc++.h>
using namespace std;
#define Mx 200001
typedef long long L;
L n,a1,a2,c;
L fun(L id){
    return (id*id*id*id*id);
}
void solve(){
    for(L i=1;i<=300;i++){
        a1=fun(i);
        c=(n-a1);
        if(c>0){
            for(L j=1;j<=300;j++){
                if(fun(j)==c){
                    printf("%lld -%lld\n",i,j);
                    return ;
                }
                if(fun(j)>c)break;
            }
        }else if(c<0){
            for(L j=1;j<=300;j++){
                if(fun(j)==abs(c)){
                    printf("%lld %lld\n",i,j);
                    return ;
                }
                if(fun(j)>abs(c))break;
            }
        }else{
            printf("%lld 0\n",i);
        }
    }
}
int main()
{
    scanf("%lld",&n);
    solve();
    return 0;
}
/// empty() lld I64d push_back() top() pop() insert() upper_bound() lower_bound() memset() max() min() scanf continue
