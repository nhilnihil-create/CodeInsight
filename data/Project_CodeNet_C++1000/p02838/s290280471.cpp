#include <iostream>
#define int64 long long int
using namespace std;
const int mod = 1e9+7;
int arr[100];
int main(){
    int n , ret = 0 , p;
    scanf("%d",&n);
    int64 x ;
    for(int i=1;i<=n;i++){
        scanf("%lld",&x);
        p=1;
        for(int j=0;j<62;j++){
            arr[j] += x&1;
            ret += (1LL * p * (x&1 ? i-arr[j] : arr[j]) )%mod ;
            ret %= mod ;
            p = (1LL * 2 * p)%mod ;
            x>>=1;
        }
    }
    printf("%d\n",ret);
}