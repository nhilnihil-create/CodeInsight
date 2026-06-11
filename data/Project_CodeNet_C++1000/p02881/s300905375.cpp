#include <cstdio>
#include <cmath>
#define ll long long
using namespace std;
int main(){
    ll n,k;
    scanf("%lld",&n);
    k=ceil(sqrt(n));
    while(k){
        if(n%k==0){
            printf("%lld",k-1+n/k-1);
            return 0;
        }
        k--;
    }
    return 0;
}
